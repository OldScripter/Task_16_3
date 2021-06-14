#include <iostream>
#include <sstream>

int main()
{
    std::string buffer;
    std::cout << "Please enter the expression <Num1><Operation><Num2>:\n";
    std::cin >> buffer;
    std::stringstream buf(buffer);

    double num_1 = 0;
    double num_2 = 0;

    char operation;
    buf >> num_1 >> operation >> num_2;

    std::string num_1_str;
    std::string num_2_str;

    double result = 0;

    if (operation == '+') result = num_1 + num_2;
    else if (operation == '-') result = num_1 - num_2;
    else if (operation == '*') result = num_1 * num_2;
    else if (operation == '/' && num_2 != 0) result = num_1 / num_2;
    else std::cout << "Operator error or division on zero!\n";

    printf("%f", result);

    return 0;
}