// Tic-Tac-Toe for two players in the terminal.
// Build: g++ -std=c++17 -Wall -o tictactoe main.cpp

#include <array>
#include <cstdlib>
#include <iostream>
#include <limits>

using Board = std::array<char, 9>;

// Prints the board. Empty squares show their number (1-9) so players
// know which number to type.
void printBoard(const Board& board) {
    std::cout << "\n";
    for (int row = 0; row < 3; ++row) {
        std::cout << " ";
        for (int col = 0; col < 3; ++col) {
            int i = row * 3 + col;
            char cell = board[i] == ' ' ? static_cast<char>('1' + i) : board[i];
            std::cout << cell;
            if (col < 2) std::cout << " | ";
        }
        std::cout << "\n";
        if (row < 2) std::cout << "---+---+---\n";
    }
    std::cout << "\n";
}

// Returns 'X' or 'O' if that player has three in a row, otherwise ' '.
char checkWinner(const Board& board) {
    const int lines[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},  // rows
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},  // columns
        {0, 4, 8}, {2, 4, 6}              // diagonals
    };
    for (const auto& line : lines) {
        char a = board[line[0]];
        if (a != ' ' && a == board[line[1]] && a == board[line[2]]) {
            return a;
        }
    }
    return ' ';
}

bool isFull(const Board& board) {
    for (char cell : board) {
        if (cell == ' ') return false;
    }
    return true;
}

// Asks the current player for a square until they enter a valid, empty one.
int getMove(const Board& board, char player) {
    while (true) {
        std::cout << "Player " << player << ", choose a square (1-9): ";
        int choice;
        if (!(std::cin >> choice)) {
            if (std::cin.eof()) std::exit(0);  // input closed, quit cleanly
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Enter a number from 1 to 9.\n";
            continue;
        }
        if (choice < 1 || choice > 9) {
            std::cout << "That square doesn't exist. Pick 1 to 9.\n";
        } else if (board[choice - 1] != ' ') {
            std::cout << "Square " << choice << " is taken. Pick another.\n";
        } else {
            return choice - 1;
        }
    }
}

// Plays one game and returns the winner ('X', 'O') or 'D' for a draw.
char playGame() {
    Board board;
    board.fill(' ');
    char player = 'X';

    while (true) {
        printBoard(board);
        board[getMove(board, player)] = player;

        if (checkWinner(board) == player) {
            printBoard(board);
            std::cout << "Player " << player << " wins!\n";
            return player;
        }
        if (isFull(board)) {
            printBoard(board);
            std::cout << "It's a draw.\n";
            return 'D';
        }
        player = (player == 'X') ? 'O' : 'X';
    }
}

int main() {
    int xWins = 0, oWins = 0, draws = 0;
    std::cout << "Tic-Tac-Toe\nTwo players take turns. Get three in a row to win.\n";

    while (true) {
        char result = playGame();
        if (result == 'X') ++xWins;
        else if (result == 'O') ++oWins;
        else ++draws;

        std::cout << "Score: X " << xWins << " | O " << oWins
                  << " | Draws " << draws << "\n";

        std::cout << "Play again? (y/n): ";
        char again;
        if (!(std::cin >> again) || (again != 'y' && again != 'Y')) break;
    }

    std::cout << "Thanks for playing!\n";
    return 0;
}
