# 📊 Adjacency Matrix Degree Calculation

## 📚 Overview
Generates random adjacency matrices, calculates row degrees (excluding self-loops), and measures computation time for different matrix sizes.

Project for **CSE106 (Discrete Mathematics)**.

## 🛠️ Features
- Random adjacency matrix (no self-loops).
- Time measurement for different sizes.
- Outputs results to `times.csv`.
- Console prints for quick view.

## 📑 Tech Stack
- **Language:** C
- **Libraries:** stdio.h, stdlib.h, time.h

## 🚀 How to Run
1. **Compile:**
    ```bash
    gcc -o matrix_time matrix_time.c
    ```
2. **Execute:**
    ```bash
    ./matrix_time
    ```

Generates console output and `times.csv` for plotting.

## 📈 Plotting
Use Gnuplot or Excel to plot computation time vs matrix size from `times.csv`.

## 💬 Observations
- Computation time grows quadratically (≈ O(n²)).

## 🧑‍💻 Author
Md. Al Amin (2019-1-65-003)
Instructor: Yeasir Rayhan (Lecturer, Dept. of CSE)
