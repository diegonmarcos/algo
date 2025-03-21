/* #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 8  // Board size (change as needed)

void printBoard(int board[N])
{
    // Print the board with queens
    char grid[N][N];
    
    // Initialize grid
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            grid[i][j] = '.';
    
    // Place queens
    for (int i = 0; i < N; i++)
        grid[i][board[i]] = 'Q';
    
    // Print grid
    for (int i = 0; i < N; i++)
	{
        for (int j = 0; j < N; j++)
            printf("%c ", grid[i][j]);
        printf("\n");
    }
    printf("\n");
}

bool isSafe(int board[N], int row, int col)
{
    // Check only up to current row
    for (int i = 0; i < row; i++)
	{
        // Check if queens share same column or diagonals
        if (board[i] == col || 
            board[i] - i == col - row || 
            board[i] + i == col + row) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int board[N], int row, int *count)
{
    // Base case: All queens placed
    if (row == N) {
        printf("Solution %d:\n", ++(*count));
        printBoard(board);
        return;
    }
    
    // Try placing queen in each column of current row
    for (int col = 0; col < N; col++)
	{
        if (isSafe(board, row, col)) {
            board[row] = col;  // Place queen
            solveNQueens(board, row + 1, count);  // Recurse for next row
        }
    }
}

int main()
{
    int board[N];
    int count = 0;
    
    // Initialize board (board[i] = column position of queen in row i)
    for (int i = 0; i < N; i++)
        board[i] = -1;
    
    solveNQueens(board, 0, &count);
    printf("Total solutions: %d\n", count);
    
    return 0;
} */