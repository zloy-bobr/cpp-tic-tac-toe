# Tic-Tac-Toe (C++)

A two-player tic-tac-toe game that runs in the terminal. I built it while learning C++ to practice arrays, functions, loops, and input validation.

## Features

- Numbered board so players know which square to pick
- Rejects invalid input (letters, numbers outside 1–9, taken squares)
- Detects wins across rows, columns, and diagonals, plus draws
- Keeps score across multiple rounds

## Example

```
 X | O | X
---+---+---
 4 | O | 6
---+---+---
 7 | 8 | 9

Player X, choose a square (1-9):
```

## How to run

You need a C++17 compiler such as g++ or clang++.

```bash
g++ -std=c++17 -Wall -o tictactoe main.cpp
./tictactoe
```

On Windows, run `tictactoe.exe` instead.

## What I learned

- Using `std::array` to store the board and passing it by `const` reference
- Validating user input with `std::cin` and recovering from bad input
- Breaking a program into small functions that each do one job

## Ideas for next steps

- Add a computer opponent (random moves first, then minimax)
- Let players pick their names
