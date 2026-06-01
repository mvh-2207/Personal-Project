#include <cmath>
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <math.h>

double const PI = 3.14;

double sum( double &a, double &b);
double substract( double &a, double &b);
double multiply( double &a, double &b);
double divide( double &a, double &b);
double double_num( double &a, double &b);
double sin_num( double &a, double &b);
double cos_num( double &a, double &b);
double tan_num( double &a, double &b);
double double_sqrt( double &a, double &b);

int main() {
    std::string operation, option;
    double num1, num2, result;

    do{
    std::cout << "Enter an operation: ";
        std::cin >> num1; // choose the first number

        std::cin >> operation;// choose +, -, *, /, ...

        std::cin >> num2; // choose the second number

        if (operation == "+") {
            result = sum(num1, num2);
        }
        else if (operation == "-") {
            result = substract(num1, num2);
        }
        else if (operation == "*") {
            result = multiply(num1, num2);
        }
        else if (operation == "/") {
            result = divide(num1, num2);
        }
        else if (operation == "^") {
            result = double_num(num1, num2);
        }
        else if (operation == "sin") {
            result = sin_num(num1, num2);
        }
        else if (operation == "cos") {
            result = cos_num(num1, num2);
        }
        else if (operation == "tan") {
            result = tan_num(num1, num2);
        }
        else if (operation == "sqrt") {
            result = double_sqrt(num1, num2);
        }


        std::cout << "The result is: " << result << std::endl;
        std::cout << "Do you want to continue(y/n): " << std::endl;
        std::cin >> option;

        if (option =="N" || option == "n") {
            std::cout << "Thanks for using our calculator!" << std::endl;
            break; // break out of the program
        }

    }while (option != "N" || option != "n");

    return 0;
}

/**
 *
 * @param a first entered number
 * @param b second entered number
 * @return the operation of two numbers
 */
double sum( double &a,  double &b) {
    return a + b;
}

double substract( double &a,  double &b) {
    return a - b;
}

double divide( double &a,  double &b) {
    return a / b;
}

double multiply( double &a,  double &b) {
    return a * b;
}

double double_num( double &a, double &b) {
    return powf(a, b);
}

/**
 *
 * @param a multiply with sin
 * @param b the number of sin
 * @return the result of the equation
 */
double sin_num (double &a, double &b) {
    return a*sin(b*PI/180.0);
}

double cos_num( double &a, double &b) {
    return a*cos(b*PI/180.0);
}

double tan_num( double &a, double &b) {
    return a*tan(b*PI/180.0);
}

double double_sqrt ( double &a, double &b) {
    return a*sqrt(b);
}





