/* #include <stdio.h>
#include <stdlib.h>

// Structure to represent an activity
typedef struct {
    int start;
    int finish;
} Activity;

// Comparison function for sorting activities by finish time
int compareActivities(const void* a, const void* b) {
    return ((Activity*)a)->finish - ((Activity*)b)->finish;
}

void activitySelection(Activity activities[], int n) {
    // Sort activities by finish time
    qsort(activities, n, sizeof(Activity), compareActivities);

    printf("Selected activities:\n");
    printf("(%d, %d)\n", activities[0].start, activities[0].finish); // Select the first activity

    int lastFinishTime = activities[0].finish;

    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastFinishTime) {
            printf("(%d, %d)\n", activities[i].start, activities[i].finish);
            lastFinishTime = activities[i].finish;
        }
    }
}

int main() {
    Activity activities[] = {
        {1, 2},
        {3, 4},
        {0, 6},
        {5, 7},
        {8, 9},
        {5, 9},
        {6, 10},
        {8, 11},
        {12, 16},
        {2, 14}
    };

    int n = sizeof(activities) / sizeof(activities[0]);

    activitySelection(activities, n);

    return 0;
} */