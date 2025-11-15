#include <stdio.h>
#include <stdbool.h>
#include<stdlib.h>
#include<time.h>

void calculator(void);
void temp_converter(void);
void number_guessing_game(void);

int main(){

    int choice;

    printf("====== Utility Toolbox ======\n");

    while (true)
    {
        printf("\nMain menu\n");
        printf("1. Calculator\n");
        printf("2. Temperature Converter\n");
        printf("3. A Number Guessing Game\n");
        printf("0. End Program\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            int c;
            while ((c = getchar()) != '\n' && c != EOF){}
            printf("Invalid input, please enter a number!\n");
            continue;
        }

        switch (choice) {
            case 0:
                printf("Goodbye!\n");
                return 0;

            case 1:
                calculator();
                break;
            
            case 2:
                temp_converter();
                break;

            case 3:
                number_guessing_game();
                break;

            default:
                printf("%d is not a correct choice!", choice);
        }
    }
    return 0;
}

void calculator(void) {
    float num1, num2, result;
    char op;

    while(true){
        printf("Enter ! to exit\n");
        printf("Enter calculation (example 1+1): ");
        scanf("%f%c%f", &num1, &op, &num2);

        switch(op) {
            case '+':
                result = num1 + num2;
                printf("Result: %.2f\n", result);
                break;

            case '-':
                result = num1 - num2;
                printf("Result: %.2f\n", result);
                break;

            case '/':
                if (num2 != 0)
                    result = num1 / num2;
                else {
                    printf("Error: Division be zero!\n");
                    continue;;
                }
                printf("Result: %.2f\n", result);
                break;

            case '*':
                result = num1 * num2;
                printf("Result: %.2f\n", result);
                break;

            default:
                printf("Error: unknown operator '%c'\n", op);
        }
    }
}

void temp_converter(void) {
    int choice;
    float temp, result;

    printf("Temperature converter\n");

    while(true){
        printf("1. Celsius to Fahrenheit\n");
        printf("2. Fahrenheit to Celsius\n");
        printf("0. Exit program\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 0)
            return;

        switch(choice){
            case 1:
                printf("Enter Celsius: ");
                scanf("%f", &temp);
                result = (temp * 9.0f / 5.0f) + 32;
                printf("%.2f Celcius is %.2f Fahrenheit\n", temp, result);
                break;
            case 2:
                printf("Enter Fahrenheit: ");
                scanf("%f", &temp);
                result = (temp - 32) * 5.0f / 9.0f;
                printf("%.2f Fahrenheit is %.2f Celsius\n", temp, result);
                break;
            default:
                printf("Choice %d invalid, pick 0-2!\n", choice);
        }
    }
}

void number_guessing_game(void) {
    int secret, guess;
    int tries = 0;

    srand(time(NULL));
    secret = rand() % 100 + 1;

    printf("Can you guess the number im thinking of? Its between 1-100\n");

    while (true)
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        tries++;

        if (guess < secret)
            printf("Too low, try again!\n");
        else if (guess > secret)
            printf("Too high, try again!\n");
        else {
            printf("Correct! The number was %d\n", secret);
            printf("You guessed it in %d tries", tries);
            break;
        }
    }
}