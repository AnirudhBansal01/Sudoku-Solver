#include <iostream>
#include <vector>
using namespace std;

// Function to take input for a Sudoku puzzle
void take_input(vector<vector<char> >& puzzle) {
    cout << "Enter the Sudoku puzzle:\n";
    for (int i = 0; i < 9; ++i) {
        vector<char> row;
        for (int j = 0; j < 9; ++j) {
            char value;
            cin >> value;
            row.push_back(value);
        }
        puzzle.push_back(row);
    }
}

// Function to print the Sudoku puzzle
void print_puzzle(const vector<vector<char> >& puzzle) {
    cout << "Sudoku puzzle:\n";
    for (int i = 0; i < 9; ++i) {
        for (int j = 0; j < 9; ++j) {
            cout << puzzle[i][j] << " ";
        }
        cout << "\n";
    }
}

// Function to check if the current placement of a value is valid in the Sudoku board
bool isValid(vector<vector<char> >& board, int i, int j, char val) {
    int sRow = i / 3 * 3;
    int sCol = j / 3 * 3;

    // Check if the value is present in the same row, column, or sub-grid
    for (int k = 0; k < 9; k++) {
        if (board[i][k] == val) return false;
        if (board[k][j] == val) return false;

        if (board[k / 3 + sRow][k % 3 + sCol] == val) return false;
    }

    return true;
}

// Backtracking function to solve the Sudoku puzzle
bool solver(vector<vector<char> >& board, int row, int col) {
    if (row == 9) return true;

    if (board[row][col] == '.') {
        for (char ch = '1'; ch <= '9'; ch++) {
            if (isValid(board, row, col, ch)) {
                board[row][col] = ch;
                if (col < 8) {
                    if (solver(board, row, col + 1)) return true;
                } else if (solver(board, row + 1, 0)) return true;

                board[row][col] = '.';
            }
        }
    } else {
        if (col < 8) {
            if (solver(board, row, col + 1)) return true;
        } else if (solver(board, row + 1, 0)) return true;
    }

    return false;
}

// Function to solve the Sudoku puzzle
void solveSudoku(vector<vector<char> >& board) {
    solver(board, 0, 0);
}

int main() {
    vector<vector<char> > puzzle;
    take_input(puzzle);
    solveSudoku(puzzle);
    print_puzzle(puzzle);

    return 0;
}

