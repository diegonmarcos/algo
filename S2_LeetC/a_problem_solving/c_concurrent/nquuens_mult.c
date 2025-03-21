/* #include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>

#define MAX_SIZE 20 // Adjust as needed

typedef struct {
    int board[MAX_SIZE][MAX_SIZE];
    int N;
    int col;
    int threadId;
    int* solutionsCount;
    pthread_mutex_t* mutex;
} ThreadData;

bool isSafe(int board[MAX_SIZE][MAX_SIZE], int row, int col, int N) {
    int i, j;

    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

void* solveNQueensThread(void* arg) {
    ThreadData* data = (ThreadData*)arg;
    int board[MAX_SIZE][MAX_SIZE];
    for(int i = 0; i < data->N; i++){
        for(int j = 0; j < data->N; j++){
            board[i][j] = data->board[i][j];
        }
    }

    int col = data->col;
    int N = data->N;

    if (col >= N) {
        pthread_mutex_lock(data->mutex);
        (*data->solutionsCount)++;
        pthread_mutex_unlock(data->mutex);
        pthread_exit(NULL);
    }

    for (int row = 0; row < N; row++) {
        if (isSafe(board, row, col, N)) {
            board[row][col] = 1;
            ThreadData nextData;
            nextData.N = N;
            nextData.col = col + 1;
            nextData.threadId = data->threadId;
            nextData.solutionsCount = data->solutionsCount;
            nextData.mutex = data->mutex;
            for(int i = 0; i < N; i++){
                for(int j = 0; j < N; j++){
                    nextData.board[i][j] = board[i][j];
                }
            }
            solveNQueensThread(&nextData);
            board[row][col] = 0; // Backtrack
        }
    }
    pthread_exit(NULL);
}

int main() {
    int N = 8;
    int numThreads = N; // One thread per starting column
    pthread_t threads[MAX_SIZE];
    ThreadData threadData[MAX_SIZE];
    int solutionsCount = 0;
    pthread_mutex_t mutex;
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < numThreads; i++) {
        for(int row = 0; row < N; row++){
            for(int col = 0; col < N; col++){
                threadData[i].board[row][col] = 0;
            }
        }

        threadData[i].N = N;
        threadData[i].col = 0;
        threadData[i].threadId = i;
        threadData[i].solutionsCount = &solutionsCount;
        threadData[i].mutex = &mutex;
        threadData[i].board[i][0] = 1;

        pthread_create(&threads[i], NULL, solveNQueensThread, &threadData[i]);
    }

    for (int i = 0; i < numThreads; i++) {
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&mutex);

    printf("Total solutions: %d\n", solutionsCount);

    return 0;
} */