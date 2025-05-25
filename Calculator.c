#include <stdio.h>
#include <math.h>

// Function declarations
double division(double a, double b);
double modulus(double a, double b);
void print_menu();

int main() {
    int choice;
    double first, second, result;

    while (1) {
        print_menu();
        scanf("%d", &choice);

        if (choice == 10) {
            printf("Thank you for using Simple Calculator.\n");
            printf("Developed by: Garv Mittal\n");
            break;
        }

        if (choice < 1 || choice > 10) {
            fprintf(stderr, "Error: Invalid menu choice.\n");
            continue;
        }

        if (choice >= 1 && choice <= 6) {
            printf("Please enter the first number: ");
            scanf("%lf", &first);
            printf("Please enter the second number: ");
            scanf("%lf", &second);
        } else if (choice >= 7 && choice <= 9) {
            printf("Please enter the angle (in radians): ");
            scanf("%lf", &first);
        }

        switch (choice) {// switch case for all operations
            case 1: result = first + second; break;
            case 2: result = first - second; break;
            case 3: result = first * second; break;
            case 4: result = division(first, second); break;
            case 5: result = modulus(first, second); break;
            case 6: result = pow(first, second); break;
            case 7: result = sin(first); break;
            case 8: result = cos(first); break;
            case 9: result = tan(first); break;
        }

        if (!isnan(result)) {
            printf("The result of your operation is: %.2lf\n", result);
        }
    }

    return 0;
}

double division(double a, double b) {// funciton for division
    if (b == 0) {
        fprintf(stderr, "Error: Division by zero is undefined.\n");
        return NAN;
    }
    return a / b;
}

double modulus(double a, double b) {// function for modulus
    int ia = (int)a;
    int ib = (int)b;
    if (ib == 0) {
        fprintf(stderr, "Error: Modulus by zero is undefined.\n");
        return NAN;
    }
    return (double)(ia % ib);
}

void print_menu() {// function to print menu for calculator
    printf("\n-------------------------------------------------\n");
    printf("Welcome to Simple Calculator\n");
    printf("Choose the operation you wish to perform:\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Power\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
}
