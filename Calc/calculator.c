#include <stdio.h>
#include <stdbool.h>

int main() {

    float num1, num2, result;
    char op;

    while(true){
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
                    return 1;
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

    return 0;
}