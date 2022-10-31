/*
 * Exercise using examples of rules SEI CERT Java Coding Standars: Concurrency 
 * 
 *  • THI02-J: Notify all waiting threads rather than a single thread
 *  • THI03-J: Always invoke wait() inside a loop
 *  • THI04-J: Ensure that threads performing blocking operations can be terminated
 *  • THI05-J: Do not use stop() to terminate threads
 *  • LCK00-J: Use private final lock objects to synchronize classes that may interact with untrusted code.
 *  • LCK01-J: Do not synchronize on objects that may be reused
 *  • LCK02-J: Do not synchronize on the class object returned by getClass
 */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.net.Socket;
import java.util.Random;
import java.util.Vector;

 /*
  *  --> THI04-J: Ensure that threads performing blocking operations can be terminated <--
  *  
  *  Threads and tasks that block on operations involving network or file I/O must provide callers with an explicit termination
  *  mechanism to prevent denial-of-service (DoS) vulnerabilities.
  *
  *  PROBLEM: This example uses a volatile done flag to indicate if it is safe to shut down the thread or it is not yet.
  *  We must not use Thread.stop() to end threads. However, in this example, when the thread is blocked on network I/O 
  *  because of the invoking of the readLine() function, it cannot respond to the newly set flag until the network I/O is complete. 
  *  Consequently, thread termination may be indefinitely delayed.
  *
  *  SOLUTION: the correct solution must terminate the blocking network I/O by closing the socket in the shutdown() method. 
  *  The readLine() method throws a SocketException when the socket is closed, consequently allowing the thread to proceed. 
  */
public final class SocketReader implements Runnable {
    private final Socket socket;
    private final BufferedReader in;
    private volatile boolean done = false;
    private final Object lock = new Object();
   
    public SocketReader(String host, int port) throws IOException {
      this.socket = new Socket(host, port);
      this.in = new BufferedReader(
          new InputStreamReader(this.socket.getInputStream())
      );
    }
   
    // Only one thread can use the socket at a particular time
    @Override public void run() {
      try {
        synchronized (lock) {
          readData();
        }
      } catch (IOException ie) {
        // Forward to handler
      }
    }

    /* Incorrect method
    public void readData() throws IOException {
        String string;
            while (!done && (string = in.readLine()) != null) {
            // Blocks until end of stream (null)
        }
    }
    */
   
    public void readData() throws IOException {
      String string;
      try {
        while ((string = in.readLine()) != null) {
          // Blocks until end of stream (null)
        }
      } finally {
        shutdown();
      }
    }
   
    public void shutdown() {
      //done = true;
      socket.close(); // <-- CORRECT SOLUTION
    }
   
    public static void main(String[] args)
                            throws IOException, InterruptedException {
      SocketReader reader = new SocketReader("somehost", 25);
      Thread thread = new Thread(reader);
      thread.start();
      Thread.sleep(1000);
      reader.shutdown(); // Shut down the thread
    }
}

/*
 * --> THI05-J: Do not use Thread.stop() to terminate threads <--
 * 
 * The the Thread.stop() is a deprecated method that causes the thread to immediately throw a ThreadDeath exception, which stops the thread.
 * Invoking Thread.stop() results in the release of all locks a thread has acquired, exposing the objects protected 
 * by those locks when those objects are in an inconsistent state. The thread might catch the ThreadDeath exception 
 * and use a finally block in an attempt to repair the inconsistent object or objects. 
 * 
 * PROBLEM: it the code below its shown a thread that fills a vector with pseudorandom numbers. The thread is forcefully stopped after a given amount of time.
 * The Thread.stop() method causes the thread to stop what it is doing and throw a ThreadDeath exception. Then, all the locks are released.
 * If the thread were in the process of adding a new integer to the vector when it was stopped, the vector would become accessible while it is in an inconsistent state.
 * 
 * SOLUTION: we must not use the Thread.stop() method to terminate threads. Instead, we should use a volatile boolean flag to indicate when it is safe to shut down the thread.
 * This flag is the done variable. The run() method checks for the value of the done variable before adding a new integer to the vector. 
 */

public final class Container implements Runnable {
    private final Vector<Integer> vector = new Vector<Integer>(1000);
    private volatile boolean done = false;
   
    public Vector<Integer> getVector() {
      return vector;
    }

    public void shutdown() {
        done = true;
      }
    
    /* Incorrect method
    @Override public synchronized void run() {
      Random number = new Random(123L);
      int i = vector.capacity();
      while (i > 0) {
        vector.add(number.nextInt(100));
        i--;
      }
    }*/

    @Override public synchronized void run() {
        Random number = new Random(123L);
        int i = vector.capacity();
        while (!done && i > 0) {
          vector.add(number.nextInt(100));
          i--;
        }
    }
   
    public static void main(String[] args) throws InterruptedException {
      Container container = new Container();
      Thread thread = new Thread(container);
      thread.start();
      Thread.sleep(5000);
      //thread.stop(); /* --> MET02-J. Do not use deprecated or obsolete classes or methods. <-- */
      container.shutdown(); // <-- CORRECT SOLUTION
    }
}