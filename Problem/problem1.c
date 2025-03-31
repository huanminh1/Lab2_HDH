#include<stdio.h>
#include<stdlib.h>
#define MAX 1683
int main() {
    FILE *file;
    int userID, movieID, rating, timestamp;
    float sum[MAX] = {0};
    int count[MAX] = {0};

    file = fopen("movie-100k_1.txt", "r");

    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    while (fscanf(file, "%d %d %d %d", &userID, &movieID, &rating, &timestamp) == 4) {
        if (movieID >= 1 && movieID <= MAX) {
            sum[movieID] += rating;
            count[movieID]++;
        }
    }

    fclose(file);

    printf("Movie ID\tAverage Rating\n");
    for (int i = 1; i < MAX; i++){
        if (count[i] > 0) {
            printf("%d\t%.2f\n", i, sum[i] / count[i]);
        }
    }
    return 0;
}
