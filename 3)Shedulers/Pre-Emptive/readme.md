# 🔁 Round Robin CPU Scheduling Simulator (C++)

This is a **C++ program** that simulates the **Round Robin (RR)** CPU scheduling algorithm. It's **menu-driven**, interactive, and prints detailed results including a **Gantt chart**, **waiting time**, and **turnaround time** for each process.

---

## 🧠 What is Round Robin Scheduling?

- **Pre-emptive** scheduling technique.
- Each process is given a fixed **time quantum**.
- If a process doesn't complete in its time slice, it is moved to the end of the queue.

---

## 🎯 Features

- Input processes with **arrival** and **burst time**.
- Simulate RR with a **user-defined time quantum**.
- Output includes:
  - Gantt chart
  - Waiting & Turnaround time per process
  - Average waiting and turnaround times

---

## 💻 How to Compile and Run

### 1. Compile:
```bash
g++ round_robin.cpp -o round_robin