#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_INPUT 100

// Function prototypes
void displayMenu();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exponent);
double factorial(int n);
double sine(double angle);
double cosine(double angle);
double tangent(double angle);
double logarithm(double value);
double squareRoot(double value);
void clearInputBuffer();

int main() {
    int choice;
    double num1, num2, result;
    char input[MAX_INPUT];

    while (1) {
        displayMenu();
        printf("\nEnter your choice: ");
        fgets(input, MAX_INPUT, stdin);
        choice = atoi(input);

        switch (choice) {
            case 1:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = add(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 2:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = subtract(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 3:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                result = multiply(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 4:
                printf("Enter two numbers: ");
                scanf("%lf %lf", &num1, &num2);
                if (num2 == 0) {
                    printf("Error: Division by zero!\n");
                } else {
                    result = divide(num1, num2);
                    printf("Result: %.2lf\n", result);
                }
                break;
            case 5:
                printf("Enter base and exponent: ");
                scanf("%lf %lf", &num1, &num2);
                result = power(num1, num2);
                printf("Result: %.2lf\n", result);
                break;
            case 6:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                result = factorial((int)num1);
                printf("Result: %.2lf\n", result);
                break;
            case 7:
                printf("Enter an angle in radians: ");
                scanf("%lf", &num1);
                result = sine(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 8:
                printf("Enter an angle in radians: ");
                scanf("%lf", &num1);
                result = cosine(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 9:
                printf("Enter an angle in radians: ");
                scanf("%lf", &num1);
                result = tangent(num1);
                printf("Result: %.2lf\n", result);
                break;
            case 10:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 <= 0) {
                    printf("Error: Logarithm undefined for non-positive values!\n");
                } else {
                    result = logarithm(num1);
                    printf("Result: %.2lf\n", result);
                }
                break;
            case 11:
                printf("Enter a number: ");
                scanf("%lf", &num1);
                if (num1 < 0) {
                    printf("Error: Square root of a negative number is not real!\n");
                } else {
                    result = squareRoot(num1);
                    printf("Result: %.2lf\n", result);
                }
                break;
            case 12:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
        clearInputBuffer();
    }

    return 0;
}

void displayMenu() {
    printf("\nAdvanced Calculator\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Factorial\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Logarithm\n");
    printf("11. Square Root\n");
    printf("12. Exit\n");
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    return a / b;
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}

double sine(double angle) {
    return sin(angle);
}

double cosine(double angle) {
    return cos(angle);
}

double tangent(double angle) {
    return tan(angle);
}

double logarithm(double value) {
    return log(value);
}

double squareRoot(double value) {
    return sqrt(value);
}

void clearInputBuffer() {
    while ((getchar()) != '\n');
}
