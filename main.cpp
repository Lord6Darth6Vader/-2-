#include <iostream>
#include <cmath>
#include <limits>

// Безопасный ввод double
double readDouble(const std::string& message) {
    double value;

    while (true) {
        std::cout << message;

        if (std::cin >> value) {
            return value;
        }

        std::cout << "Error: please enter a valid number!\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

// Безопасный ввод int
int readInt(const std::string& message) {
    int value;

    while (true) {
        std::cout << message;

        if (std::cin >> value) {
            return value;
        }

        std::cout << "Error: please enter a valid integer!\n";

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}

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

        // Безопасный ввод пункта меню
        choice = readInt("\nChoose operation: ");

        double num1, num2;

        switch (choice) {
            case 1:
                num1 = readDouble("Enter first number: ");
                num2 = readDouble("Enter second number: ");

                std::cout << "Result: " << num1 + num2 << '\n';
                break;

            case 2:
                num1 = readDouble("Enter first number: ");
                num2 = readDouble("Enter second number: ");

                // Можно вводить отрицательные числа.
                // Отрицательный результат тоже абсолютно допустим.
                std::cout << "Result: " << num1 - num2 << '\n';
                break;

            case 3:
                num1 = readDouble("Enter first number: ");
                num2 = readDouble("Enter second number: ");

                std::cout << "Result: " << num1 * num2 << '\n';
                break;

            case 4:
                num1 = readDouble("Enter first number: ");
                num2 = readDouble("Enter second number: ");

                if (num2 == 0) {
                    std::cout << "Error: division by zero!\n";
                } else {
                    std::cout << "Result: " << num1 / num2 << '\n';
                }

                break;

            case 5: {
                num1 = readDouble("Enter number: ");
                int n = readInt("Enter power N: ");

                std::cout << "Result: " << std::pow(num1, n) << '\n';
                break;
            }

            case 6:
                num1 = readDouble("Enter number: ");

                if (num1 < 0) {
                    std::cout
                        << "Error: cannot calculate square root of a negative number!\n";
                } else {
                    std::cout << "Result: " << std::sqrt(num1) << '\n';
                }

                break;

            case 7:
                num1 = readDouble("Enter number: ");

                std::cout << "1 percent: " << num1 / 100 << '\n';
                break;

            case 8: {
                int number = readInt("Enter integer: ");

                if (number < 0) {
                    std::cout
                        << "Error: factorial cannot be calculated for a negative number!\n";
                    break;
                }

                // 20! — максимальное значение, которое помещается
                // в unsigned long long.
                if (number > 20) {
                    std::cout
                        << "Error: factorial is too large! Enter a number from 0 to 20.\n";
                    break;
                }

                unsigned long long factorial = 1;

                for (int i = 1; i <= number; i++) {
                    factorial *= i;
                }

                std::cout << "Factorial: " << factorial << '\n';
                break;
            }

            case 9:
                std::cout << "Program finished.\n";
                break;

            default:
                std::cout
                    << "Unknown operation. Enter a number from 1 to 9.\n";
        }

    } while (choice != 9);

    return 0;
}
