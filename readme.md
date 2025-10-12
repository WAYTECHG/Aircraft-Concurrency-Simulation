## 🛫 Aircraft Concurrency Simulation (C)

### 📘 Overview

This project demonstrates the use of  **POSIX threads (pthreads)** ,  **semaphores** , and **mutexes** to simulate concurrency control in an  **airport landing system** .

It includes two main simulations:

1. **Runway Landing Simulation** — manages aircraft access to a single runway using a semaphore.
2. **Airspace Control Simulation** — coordinates multiple aircraft entering limited airspace and landing with synchronized runway usage.

These programs showcase  **synchronization** ,  **mutual exclusion** , and **resource allocation** concepts used in  **Operating Systems** .

---

### ⚙️ Features

* 🧵 Multithreading using `pthread` library
* 🚦 Synchronization using `semaphore` and `mutex`
* 🛬 Controlled runway access to prevent collision
* 🌤️ Simulated limited airspace capacity
* ⏱️ Realistic delays using `sleep()` to represent aircraft landing times

---

### 🧩 Files Included

| File                   | Description                                                                                        |
| ---------------------- | -------------------------------------------------------------------------------------------------- |
| `runway_landing.c`   | Simulation of 3 aircraft requesting a single runway using a semaphore                              |
| `airspace_control.c` | Simulation of 5 aircraft sharing limited airspace and synchronized landing using semaphore + mutex |

---


### 🧠 Concepts Demonstrated

* **Semaphore Control** for resource access
* **Mutex Locks** for thread-safe I/O
* **Thread Management** using `pthread_create` and `pthread_join`
* **Critical Section Protection**

---

### ⚖️ License

This project is shared for  **educational and portfolio purposes only** .

Reproduction, modification, or redistribution of the source code without permission is  **not allowed** .
