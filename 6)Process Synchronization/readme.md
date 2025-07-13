# 🤝 Producer-Consumer Problem in C (Process Synchronization)

This project simulates the **Producer-Consumer Problem** — a classic problem in **Operating Systems and process synchronization**. It uses **POSIX threads**, **mutexes**, and **semaphores** to handle concurrency.

---

## 🧠 What is the Producer-Consumer Problem?

A synchronization problem where:
- The **Producer** creates data and puts it into a buffer.
- The **Consumer** takes data from the buffer.
- The buffer has a **limited size**, and we must **avoid race conditions**, **buffer overflows**, or **underflows**.

---

## 🔧 Technologies Used

- C language
- POSIX Threads (`pthread`)
- Semaphores (`semaphore.h`)
- Mutex Locks

---

## 💻 How to Compile and Run

### 1. Compile
```bash
gcc producer_consumer.c -o pc -lpthread
