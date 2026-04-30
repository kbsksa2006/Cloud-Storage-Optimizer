#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100
#define NAME 50

// Structure (DSA concept)
typedef struct {
    char name[NAME];
    int size;       // weight
    int importance; // value
} File;

// Function to input files
int inputFiles(File files[]) {
    int n;
    printf("\nEnter number of files: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nFile %d name: ", i + 1);
        scanf("%s", files[i].name);

        printf("Size (MB): ");
        scanf("%d", &files[i].size);

        printf("Importance: ");
        scanf("%d", &files[i].importance);
    }
    return n;
}

// Display files
void displayFiles(File files[], int n) {
    printf("\n--- File List ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d. %s | Size: %d MB | Importance: %d\n",
               i + 1, files[i].name, files[i].size, files[i].importance);
    }
}

// Knapsack function using Dynamic Programming
int knapsack(File files[], int n, int capacity, int dp[MAX][MAX]) {

    // Build DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {

            if (i == 0 || w == 0)
                dp[i][w] = 0;

            else if (files[i - 1].size <= w) {
                int include = files[i - 1].importance +
                              dp[i - 1][w - files[i - 1].size];
                int exclude = dp[i - 1][w];

                dp[i][w] = (include > exclude) ? include : exclude;
            }

            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    return dp[n][capacity];
}

// Function to print selected files (Backtracking)
void printSelected(File files[], int n, int capacity, int dp[MAX][MAX]) {

    int res = dp[n][capacity];
    int w = capacity;

    printf("\nSelected Files:\n");

    for (int i = n; i > 0 && res > 0; i--) {

        if (res == dp[i - 1][w])
            continue;

        else {
            printf("-> %s (Size: %d MB, Importance: %d)\n",
                   files[i - 1].name,
                   files[i - 1].size,
                   files[i - 1].importance);

            res -= files[i - 1].importance;
            w -= files[i - 1].size;
        }
    }
}

// Menu
void menu() {
    printf("\n===== Cloud Storage Optimizer =====\n");
    printf("1. Enter Files\n");
    printf("2. Display Files\n");
    printf("3. Optimize Storage (Knapsack)\n");
    printf("4. Exit\n");
}

// Main function
int main() {
    File files[MAX];
    int n = 0;
    int choice, capacity;
    int dp[MAX][MAX];

    while (1) {
        menu();
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                n = inputFiles(files);
                break;

            case 2:
                if (n == 0)
                    printf("\nNo files available!\n");
                else
                    displayFiles(files, n);
                break;

            case 3:
                if (n == 0) {
                    printf("\nEnter files first!\n");
                    break;
                }

                printf("\nEnter storage capacity (MB): ");
                scanf("%d", &capacity);

                int maxImportance = knapsack(files, n, capacity, dp);

                printf("\nMaximum Importance: %d\n", maxImportance);

                printSelected(files, n, capacity, dp);
                break;

            case 4:
                printf("\nExiting...\n");
                exit(0);

            default:
                printf("\nInvalid choice!\n");
        }
    }

    return 0;
}