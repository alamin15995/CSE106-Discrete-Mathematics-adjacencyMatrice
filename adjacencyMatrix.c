#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_N 10    // Minimum matrix size
#define MAX_N 100   // Maximum matrix size
#define STEP 10     // Step size for n

long long global_sum = 0;   // Global sum of all edges

int main() {
    // Seed the random number generator using current time
    // (srand(time(NULL)) ensures a different sequence of rand() values each run)
    srand(time(NULL));  //&#8203;:contentReference[oaicite:4]{index=4}

    // Open an output CSV file to record timings
    // The CSV will have two columns: matrix size and time in seconds
    FILE *fp = fopen("times.csv", "w");
    if (!fp) {
        fprintf(stderr, "Error opening file for writing.\n");
        return 1;
    }
    fprintf(fp, "n,time_sec\n");  // CSV header

    // Buffer for the largest matrix (100x100)
    int adj_matrix[MAX_N][MAX_N];

    // Loop over desired matrix sizes
    for (int n = MIN_N; n <= MAX_N; n += STEP) {
        global_sum = 0;  // reset global sum for each size

        // Start timing the computation
        clock_t start = clock();

        // Fill the adjacency matrix and compute row sums
        for (int i = 0; i < n; i++) {
            int row_degree = 0;  // sum of row i
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    // No self-loops: force diagonal to 0
                    adj_matrix[i][j] = 0;
                    // (row_degree is already 0 at start of row)
                } else {
                    // Randomly assign 0 or 1 for adjacency
                    adj_matrix[i][j] = rand() % 2;
                    row_degree += adj_matrix[i][j];
                    global_sum += adj_matrix[i][j];
                }
            }
            // (Optional) We could use row_degree here, e.g., print or store it
        }

        // End timing
        clock_t end = clock();
        double cpu_time = (double)(end - start) / CLOCKS_PER_SEC;  // seconds&#8203;:contentReference[oaicite:5]{index=5}&#8203;:contentReference[oaicite:6]{index=6}

        // Output the size and elapsed time
        printf("n=%d, time=%.6f sec\n", n, cpu_time);
        fprintf(fp, "%d,%.6f\n", n, cpu_time);
    }

    fclose(fp);
    return 0;
}
