<h1 align="center">📧 Email Route Optimizer</h1>

<p align="center">
  <strong>Dynamic programming solutions for combinatorial route optimisation problems</strong>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white"/>
  <img src="https://img.shields.io/badge/Dynamic%20Programming-Algorithm-orange?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Combinatorics-Problem%20Solving-blueviolet?style=for-the-badge"/>
</p>

---

## 📖 About

A Design and Analysis of Algorithms project implementing **dynamic programming** solutions for the email delivery routing problem. The project explores both top-down (memoisation) and bottom-up (tabulation) approaches to find the optimal delivery path across a network of nodes.

## ✨ Features

- 🔁 **Recursive + Memoisation** — Top-down DP approach (`p3a.cpp`)
- 📊 **Tabulation** — Bottom-up DP approach (`p3b.cpp`)
- 🔢 **Big Number Support** — Template-based implementation for large inputs
- ⚡ **Complexity Analysis** — Compared against brute-force baseline

## 🛠️ Tech Stack

| | |
|---|---|
| Language | C++ |
| Paradigm | Dynamic Programming |
| Concepts | Memoisation, Tabulation, Recursion |
| Build | g++ |

## 🚀 Getting Started

```bash
git clone https://github.com/HamzaSaeed31/Email-Route-Optimizer.git
cd Email-Route-Optimizer

# Top-down approach
g++ -o p3a p3a.cpp -O2
./p3a

# Bottom-up approach
g++ -o p3b p3b.cpp -O2
./p3b
```

## 📐 Algorithm Overview

```
Given: A directed graph of delivery nodes
Goal:  Count or find the optimal email delivery route
DP state: dp[node] = number of ways to reach destination
```
