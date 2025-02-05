#include <iostream>

#include <string>

using std::string;

int main()
{
    int valueOne, valueTwo;
    std::cout << "First value:\n> ";
    std::cin >> valueOne;
    
    std::cout << "Second value:\n> ";
    std::cin >> valueTwo;

    char chosenOperator;
    std::cout << "What operation would you like to perform? (+, -, *, /, %):\n> ";
    std::cin >> chosenOperator;

    int output;

    switch (chosenOperator) {
        case '+':
            output = valueOne + valueTwo;
            break;
        case '-':
            output = valueOne - valueTwo;
            break;
        case '*':
            output = valueOne * valueTwo;
            break;
        case '/':
            output = valueOne / valueTwo;
            break;
        case '%':
            output = valueOne % valueTwo;
            break;
        default:
            output = 0;
            std::cout << "\033[1;31mInvalid operator\n\033[0m";
            break;
    }

    std::cout << valueOne << " " << chosenOperator << " " << valueTwo << " = " << output << "\n";

    return EXIT_SUCCESS;
}