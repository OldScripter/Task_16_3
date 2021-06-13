#include <iostream>
#include <cassert>
#include <sstream>

double GetDoubleFromSubString(int start_index, int end_index, std::string str)
{
    assert(start_index >= 0 && start_index < str.length());
    assert(end_index >= 0 && end_index < str.length());

    std::cout << "Your string on input: " << str << "\n";
    std::string sub_string;

    for (int i = start_index; i < end_index; i++)
    {
        sub_string += str[i];
    }
    return std::stod(sub_string);
}

int main() {



    std::string expression;

    std::cout << "Please enter the expresion in format <first_num><operation><second_num>: ";
    std::cin >> expression;

    double first_number = 0;
    double second_number = 0;
    char operation = 0;

    for (int i = 0; i < expression.size(); i++)
    {
        if (expression[i] == '+' ||
            expression[i] == '-' ||
            expression[i] == '*' ||
            expression[i] == '/')
        {
            first_number = GetDoubleFromSubString(0, i, expression);
            second_number = GetDoubleFromSubString(i + 1, expression.size(), expression);
            operation = expression[i];

            std::cout << "NUM_1: " << first_number <<'\n';
            std::cout << "NUM_2: " << second_number <<'\n';
            std::cout << "Oper: " << operation <<'\n';

            break;
        }
    }
    double res;

    if (operation == '+') res = first_number + second_number;
    else if (operation == '-') res = first_number - second_number;
    else if (operation == '*') res = first_number * second_number;
    else if (operation == '/')
    {
        if (second_number == 0)
        {
            std::cout << "Division on zero!\n";
            return 1;
        }
        else res = first_number / second_number;
    }

    std::cout << first_number << operation << second_number << " = " << "\n";
    std::printf("%.f \n" , res);

    return 0;
}
