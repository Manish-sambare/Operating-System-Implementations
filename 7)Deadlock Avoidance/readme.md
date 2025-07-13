# 🔐 Banker's Algorithm in C (Deadlock Avoidance)

This project simulates the **Banker's Algorithm** in C — a deadlock avoidance strategy used in **Operating Systems**. It ensures that resource allocation remains in a **safe state**.

---

## 📚 What is Banker's Algorithm?

The Banker's Algorithm checks whether it's **safe to allocate resources** to processes without entering a deadlock. It uses:
- **Allocation Matrix**
- **Max Matrix**
- **Available Resources**
- Calculates the **Need Matrix**
- Determines a **Safe Sequence** if possible.

---

## 💻 How to Compile and Run

### Compile:
```bash
gcc bankers_algorithm.c -o banker
