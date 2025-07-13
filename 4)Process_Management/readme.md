# 🧠 Process Management in C: Fork, Orphan, and Zombie Processes

This project demonstrates **process management** using `fork()` in C. It showcases how the parent and child processes operate independently and introduces two important process types: **Orphan** and **Zombie** processes.

---

## 🔧 What This Code Does

### ✅ Part A: Fork and Sorting
- The **parent process** sorts a static array in **ascending order**.
- The **child process** sorts the same array in **descending order**.

### ✅ Part B: Orphan Process
- The parent exits before the child.
- The child continues executing and becomes an **orphan**, adopted by the `init` (or `systemd`) process.

### ✅ Part C: Zombie Process
- The parent does **not call `wait()`**, causing the child to become a **zombie process** after it finishes.

---

## 📂 Files

| File Name       | Description                            |
|----------------|----------------------------------------|
| `orphan_Zombie.c` | Main C file with complete implementation |
| `README.md`     | This file                              |

---

## 🧪 How to Run

### Step 1: Compile the code
```bash
gcc orphan_Zombie.c -o orphan_Zombie
