/* #include <stdio.h>

// Recursive function to generate permutations
void permute(int *arr, int start, int end)
{
    if (start == end)
	{
        // Print the permutation
        for (int i = 0; i <= end; i++)
            printf("%d ", arr[i]);
        printf("\n");
        return;
    }
    
    for (int i = start; i <= end; i++)
	{
        // Swap elements
        int temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
        
        // Recursive call
        permute(arr, start + 1, end);
        
        // Backtrack (restore the array)
        temp = arr[start];
        arr[start] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[] = {1, 2, 3}; // Example array
    int n = sizeof(arr) / sizeof(arr[0]);
    
    permute(arr, 0, n - 1);
    
    return 0;
} */