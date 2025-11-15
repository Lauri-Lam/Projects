#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

float calculateAverage(int grades[], int count);
int getMin(int grades[], int count);
int getMax(int grades[], int count);

int main(){
    int count = 0;
    int grades[100];

    printf("\n====== Students Grading System ======\n");

    while(true) {
        printf("Enter number of students (0 to exit): ");
        scanf("%d", &count);

        if (count == 0)
            break;

        if (count < 0 || count > 100) {
            printf("Enter a number between 1 and 100!\n");
            continue;
        }

        for (int i = 0; i < count; i++) {
            printf("Enter grade for student %d: ", i + 1);
            scanf("%d", &grades[i]);
        }

        float avg = calculateAverage(grades, count);
        int min = getMin(grades, count);
        int max = getMax(grades, count);

        printf("\n====== Results ======\n");
        printf("\nAverage grade: %.2f\n", avg);
        printf("Lowest grade: %d\n", min);
        printf("Highest Grade: %d\n", max);
    }
    printf("Exiting program...\n");
    Sleep(2000);
    return 0;
}

float calculateAverage(int grades[], int count) {
    int sum = 0;

    for (int i = 0; i < count; i++) {
        sum += grades[i];
    }

    return (float)sum / count;
}

int getMin(int grades[], int count) {
    int min = grades[0];

    for (int i = 1; i < count; i++) {
        if (grades[i] < min)
            min = grades[i];
    }
    return min;
}

int getMax(int grades[], int count) {
    int max = grades[0];

    for (int i = 1; i < count; i++) {
        if (grades[i] > max)
            max = grades[i];
    }
    return max;
}