#include <iostream>
#include <cmath>

int main() {
    int choice;

    do {
        std::cout << "\n===== CALCULATOR =====\n";
        std::cout << "1. Add two numbers\n";
        std::cout << "2. Subtract first from second\n";
        std::cout << "3. Multiply two numbers\n";
        std::cout << "4. Divide first by second\n";
        std::cout << "5. Raise first number to power N\n";
        std::cout << "6. Square root\n";
        std::cout << "7. Find 1 percent of number\n";
        std::cout << "8. Factorial\n";
        std::cout << "9. Exit\n";

        std::cout << "\nChoose operation: ";
        std::cin >> choice;

        double num1, num2;

        switch (choice) {
            case 1:
                std::cout << "Enter first number: ";
                std::cin >> num1;

                std::cout << "Enter second number: ";
                std::cin >> num2;

                std::cout << "Result: " << num1 + num2 << '\n';
                break;

            case 2:
                std::cout << "Enter first number: ";
                std::cin >> num1;

                std::cout << "Enter second number: ";
                std::cin >> num2;

                // Вычитаем первое число ИЗ второго
                std::cout << "Result: " << num2 - num1 << '\n';
                break;

            case 3:
                std::cout << "Enter first number: ";
                std::cin >> num1;

                std::cout << "Enter second number: ";
                std::cin >> num2;

                std::cout << "Result: " << num1 * num2 << '\n';
                break;

            case 4:
                std::cout << "Enter first number: ";
                std::cin >> num1;

                std::cout << "Enter second number: ";
                std::cin >> num2;

                if (num2 == 0) {
                    std::cout << "Error: division by zero!\n";
                } else {
                    std::cout << "Result: " << num1 / num2 << '\n';
                }

                break;

            case 5: {
                int n;

                std::cout << "Enter number: ";
                std::cin >> num1;

                std::cout << "Enter power N: ";
                std::cin >> n;

                std::cout << "Result: " << std::pow(num1, n) << '\n';
                break;
            }

            case 6:
                std::cout << "Enter number: ";
                std::cin >> num1;

                if (num1 < 0) {
                    std::cout << "Error: cannot calculate square root of a negative number!\n";
                } else {
                    std::cout << "Result: " << std::sqrt(num1) << '\n';
                }

                break;

            case 7:
                std::cout << "Enter number: ";
                std::cin >> num1;

                std::cout << "1 percent: " << num1 / 100 << '\n';
                break;

            case 8: {
                int number;
                unsigned long long factorial = 1;

                std::cout << "Enter integer: ";
                std::cin >> number;

                if (number < 0) {
                    std::cout << "Error: factorial cannot be calculated for a negative number!\n";
                } else {
                    for (int i = 1; i <= number; i++) {
                        factorial *= i;
                    }

                    std::cout << "Factorial: " << factorial << '\n';
                }

                break;
            }

            case 9:
                std::cout << "Program finished.\n";
                break;

            default:
                std::cout << "Unknown operation. Enter a number from 1 to 9.\n";
        }

    } while (choice != 9);

    return 0;
}
