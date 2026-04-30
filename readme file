# 📦 Cloud Storage Optimizer using Knapsack (C - DSA Project)

## 📌 Project Overview

The **Cloud Storage Optimizer** is a C-based project that uses the **0/1 Knapsack Algorithm** (Dynamic Programming) to select the most important files that can be stored within a limited storage capacity.

This project demonstrates how Data Structures and Algorithms (DSA) can be applied to solve real-world optimization problems efficiently.

---

## 🎯 Objective

To maximize the total importance of files stored in a cloud system without exceeding the given storage capacity.

---

## 🧠 Concept Used

* Dynamic Programming
* 0/1 Knapsack Problem
* Structures in C
* Arrays
* Backtracking

---

## ⚙️ Problem Definition

Given:

* A set of files
* Each file has:

  * Size (in MB) → Weight
  * Importance → Value
* A storage limit (capacity)

Goal:

* Select a subset of files such that:

  * Total size ≤ Storage capacity
  * Total importance is maximized

---

## 🏗️ Project Features

* Menu-driven program
* User input for files (name, size, importance)
* Displays all files
* Optimizes file selection using Knapsack
* Shows:

  * Maximum importance achieved
  * Selected files

---

## 🧩 Algorithm Used

### 0/1 Knapsack Algorithm

For each file:

* Either include it OR exclude it (no partial selection)

### Recurrence Relation:

```
dp[i][w] = max(
    value[i-1] + dp[i-1][w - weight[i-1]],
    dp[i-1][w]
)
```

---

## 📊 Time & Space Complexity

* Time Complexity: O(n × capacity)
* Space Complexity: O(n × capacity)

---

## 💻 Technologies Used

* Programming Language: C
* Concepts: DSA (Dynamic Programming)

---



## 🧾 Sample Input

```
Number of files: 3

File1  Size: 10  Importance: 60  
File2  Size: 20  Importance: 100  
File3  Size: 30  Importance: 120  

Storage Capacity: 50
```

---

## ✅ Sample Output

```
Maximum Importance: 220

Selected Files:
File2
File3
```

---

## 📚 Real-Life Applications

* Cloud storage management
* File backup optimization
* Memory allocation
* Resource management systems

---

## 🔮 Future Enhancements

* File handling (load data from file)
* Graphical user interface
* Fractional knapsack version
* Sorting files by priority

---

## 📌 Conclusion

This project successfully demonstrates how the Knapsack algorithm can be applied to optimize resource usage in cloud storage systems. It highlights the importance of Dynamic Programming in solving complex optimization problems efficiently.

---
