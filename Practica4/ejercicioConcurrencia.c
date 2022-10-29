/**
 * Exercise using examples of rules SEI CERT C Coding Standars: Concurrency 
*/

#include <stdatomic.h>
#include <stddef.h>
#include <threads.h>

/**
 * --> CON31-C. Do not destroy a mutex while it is locked <--
 * 
 * The mutex is used to protect shared data being concurrently accessed by multiple threads.
 * If a mutex is destroyed while a thread is blocked waiting for it, the behavior is undefined.
 * 
 * PROBLEM: The next code creates several threads that accesse to de do_work() function, passing an unique ID.
 * The do_work() function initializes the lock mutex if the argument passed is a 0 and destroys the mutex if max_threads-1.
 * In all the other cases, normal process is executed. 
 * All-in-all, this code has some race conditions, allowing the mutex to be destroyed before it is unlocked. 
 * Also, there is guarantee that lock will be initialized before it is passed to mtx_lock()
 * 
 * SOLUTION: We must initialize the mutex in the main function and before creating the threads. Also, we must destroy the mutex in main.
*/

mtx_t lock;
/* Atomic so multiple threads can modify safely */
atomic_int completed = ATOMIC_VAR_INIT(0);
enum { max_threads = 5 };
 
/*int do_work_bad(void *arg) {
    int *i = (int *)arg;
    
    if (*i == 0) { //Creation thread 
        if (thrd_success != mtx_init(&lock, mtx_plain)) {
            // Handle error 
        }
        atomic_store(&completed, 1);
    } else if (*i < max_threads - 1) { // Worker thread
        if (thrd_success != mtx_lock(&lock)) {
            // Handle error
        }

        // Access data protected by the lock 
        atomic_fetch_add(&completed, 1);
        if (thrd_success != mtx_unlock(&lock)) {
            // Handle error
        }
    } else { // Destruction thread
        mtx_destroy(&lock);
    }

    return 0;
}*/

int do_work_well(void *dummy) {
    if (thrd_success != mtx_lock(&lock)) {
        /* Handle error */
    }

    /* Access data protected by the lock */
    atomic_fetch_add(&completed, 1);
    if (thrd_success != mtx_unlock(&lock)) {
        /* Handle error */
    }
    
    return 0;
}
  
int main(void) {
    thrd_t threads[max_threads];
        
    if (thrd_success != mtx_init(&lock, mtx_plain)) {
        /* Handle error */
    }

    for (size_t i = 0; i < max_threads; i++) {
        if (thrd_success != thrd_create(&threads[i], do_work_well, NULL)) {
        /* Handle error */
        }
    }

    for (size_t i = 0; i < max_threads; i++) {
        if (thrd_success != thrd_join(threads[i], 0)) {
        /* Handle error */
        }
    }
    
    mtx_destroy(&lock);
    return 0;
}


/**
 * --> CON43-C. Do not allow data races in multithreaded code <--
 * 
 * We must use synchronization techniques to avoid race conditions in our software. Such data races can lead to unexpected behavior.
 * 
 * PROBLEM: The next code is part of a multithreaded program of a bank. There are two functions, debit() and credit(), for transfers (subbstraction and addition).
 * This operations are not atomic, so race conditions can ocurr.
 * 
 * SOLUTION: Two different ones:
 * 1. Use a mutex to protect the critical section of the code (as seen before).
 *      a. In main we init and destroy mutex.
 *      b. In debit() and credit() we lock and unlock mutex.
 * 2. Declare the variable as atomic. This way, the compiler will generate the necessary code to ensure that the variable is accessed atomically.
*/

//static volatile int account_balance;
atomic_int account_balance;
 
void debit(int amount) {
  account_balance -= amount;
}
 
void credit(int amount) {
  account_balance += amount;
}