#include<stdio.h>
#include<stdbool.h>

int main(){
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
            break;

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
    return 0;
}