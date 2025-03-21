/* #include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define N 4  // Number of cities (change as needed)

// Example distance matrix (adjust for your problem)
int dist[N][N] =
{
    {0, 10, 15, 20},
    {10, 0, 35, 25},
    {15, 35, 0, 30},
    {20, 25, 30, 0}
};

// Keep track of visited cities
bool visited[N];

// Store the best tour and its cost
int bestTour[N+1];
int currentTour[N+1];
int minCost = INT_MAX;

void copyTour()
{
    for (int i = 0; i <= N; i++)
        bestTour[i] = currentTour[i];
}

void tsp(int pos, int count, int cost)
{
    // Base case: all cities visited
    if (count == N && dist[pos][0] > 0)
	{
        // Add cost to return to starting city
        int totalCost = cost + dist[pos][0];
        
        if (totalCost < minCost)
		{
            minCost = totalCost;
            currentTour[N] = 0;  // Return to starting city
            copyTour();
        }
        return;
    }

    // Try each unvisited city
    for (int i = 0; i < N; i++)
	{
        if (!visited[i] && dist[pos][i] > 0)
		{
            visited[i] = true;
            currentTour[count] = i;
            
            tsp(i, count + 1, cost + dist[pos][i]);
            
            // Backtrack
            visited[i] = false;
        }
    }
}

int main()
{
    // Initialize arrays
    for (int i = 0; i < N; i++)
	{
        visited[i] = false;
    }
    
    // Start from city 0
    visited[0] = true;
    currentTour[0] = 0;
    
    // Find optimal tour
    tsp(0, 1, 0);
    
    // Print result
    printf("Shortest tour: ");
    for (int i = 0; i <= N; i++)
	{
        printf("%d ", bestTour[i]);
    }
    printf("\nTour length: %d\n", minCost);
    
    return 0;
} */