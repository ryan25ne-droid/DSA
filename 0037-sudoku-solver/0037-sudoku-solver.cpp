class Solution {
public:
    bool isUnique(vector<vector<char>>&sudoku, int row, int col, char num){
        int n = sudoku.size();
        // Column and row check
        for (int i = 0; i < n; i++) {
            if (sudoku[i][col] == num) return false;
            if (sudoku[row][i] == num) return false;
        }
        // 3x3 subgrid check
        int r = (row / 3) * 3;
        int c = (col / 3) * 3;
        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                if (sudoku[i][j] == num) return false;
            }
        }
        return true;
    }

    bool sudokuSolver(vector<vector<char>>& sudoku, int row, int col) {
        if (col == 9) return sudokuSolver(sudoku, row + 1, 0);
        if (row == 9) return true; // solved

        if (sudoku[row][col] != '.') {
            return sudokuSolver(sudoku, row, col + 1);
        }

        for (char digit = '1'; digit <= '9'; digit++) {
            if (isUnique(sudoku, row, col, digit)) {
                sudoku[row][col] = digit;
                if (sudokuSolver(sudoku, row, col + 1)) return true;
                sudoku[row][col] = '.'; // backtrack
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>>& sudoku) {
        sudokuSolver(sudoku, 0, 0);
    }
};