#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>

int main() {
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
    return 0;
}