#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define SIZE 5  // Buffer size

int buffer[SIZE];
int in = 0, out = 0;

sem_t empty, full;      // Semaphores
pthread_mutex_t mutex;  // For mutual exclusion

void* producer(void* arg) {
    int item;
    for (int i = 0; i < 10; i++) {
        item = rand() % 100;  // Random item

        sem_wait(&empty);              // Wait for empty space
        pthread_mutex_lock(&mutex);    // Enter critical section

        buffer[in] = item;
        printf("Producer produced: %d at %d\n", item, in);
        in = (in + 1) % SIZE;

        pthread_mutex_unlock(&mutex);  // Exit critical section
        sem_post(&full);               // Signal that buffer has data

        sleep(1); // Simulate time to produce
    }

    pthread_exit(NULL);
}

void* consumer(void* arg) {
    int item;
    for (int i = 0; i < 10; i++) {
        sem_wait(&full);               // Wait for available item
        pthread_mutex_lock(&mutex);    // Enter critical section

        item = buffer[out];
        printf("Consumer consumed: %d from %d\n", item, out);
        out = (out + 1) % SIZE;

        pthread_mutex_unlock(&mutex);  // Exit critical section
        sem_post(&empty);              // Signal that buffer has space

        sleep(2); // Simulate time to consume
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t prod, cons;

    sem_init(&empty, 0, SIZE);  // Initially, all slots are empty
    sem_init(&full, 0, 0);      // Initially, no item in buffer
    pthread_mutex_init(&mutex, NULL);

    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}
