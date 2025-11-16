#include <stdio.h>
#include <stdbool.h>

#define MAX_TASKS 100

typedef struct
{
    char title[100];
    bool done;
}Task;

void clearLine(void);
void addTask(Task tasks[], int *count);
void listTasks(Task tasks[], int count);
void markTaskDone(Task tasks[], int count);

int main(){
    Task tasks[MAX_TASKS];
    int count = 0;
    int choice;

    printf("\n====== To-Do List Manager ======\n");

    while (true)
    {
        printf("\nMain menu\n");
        printf("1. Add task\n");
        printf("2. List tasks\n");
        printf("3. Mark task as done\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            clearLine();
            printf("Invalid input, try again!\n");
            continue;
        }
        clearLine();

        switch(choice) {
            case 0:
                printf("Ending program...\n");
                return 0;
            case 1:
                addTask(tasks, &count);
                break;
            case 2:
                listTasks(tasks, count);
                break;
            case 3:
                markTaskDone(tasks, count);
                break;
            default:
                printf("Invalid choice, try again!\n");
        }
    }
    return 0;
}

void clearLine(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

void addTask(Task tasks[], int *count) {
    if (*count >= MAX_TASKS) {
        printf("\nTask list is full!\n");
        return;
    }

    printf("\nEnter task description: ");

    if (scanf(" %99[^\n]", tasks[*count].title) != 1) {
        clearLine();
        printf("Failed to read task.\n");
        return;
    }

    tasks[*count].done = false;
    (*count)++;

    printf("Task added.\n");
}

void listTasks(Task tasks[], int count) {
    if (count == 0) {
        printf("\nTasks list is empty.\n");
        return;
    }

    printf("\n====== Task List ======\n");

    for (int i = 0; i < count; i++) {
        printf("%2d. [%c] %s\n",
                i + 1,
                tasks[i].done ? 'X' : ' ',
                tasks[i].title);
    }
}

void markTaskDone(Task tasks[], int count) {
    if (count == 0) {
        printf("\nNo tasks to mark.\n");
        return;
    }
    listTasks(tasks, count);

    int index;

    printf("\nEnter task number to marked done: ");

    if (scanf("%d", &index) != 1) {
        clearLine();
        printf("Invalid input!\n");
        return;
    }
    clearLine();

    if (index < 1 || index > count) {
        printf("Task number has to be between 1 and %d\n", count);
        return;
    }

    tasks[index - 1].done = true;
    printf("Task %d has been marked as done!\n", index);
}