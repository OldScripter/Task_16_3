#include <iostream>
#include <sstream>

int main()
{
    std::string buffer;
    std::cout << "Please enter the expression <Num1><Operation><Num2>:\n";
    std::cin >> buffer;

    char operation = 0;
    double num_1 = 0;
    double num_2 = 0;

    std::string num_1_str;
    std::string num_2_str;

    for (int i = 0; i < buffer.length(); i++)
    {

        if (buffer[i] == '+' || buffer[i] == '-' || buffer[i] == '*' || buffer[i] == '/')
        {
            operation = buffer[i];
        }
        else if (operation == 0)
        {
            num_1_str += buffer[i];
        }
        else
        {
            num_2_str += buffer[i];
        }
    }

    num_1 = std::stod(num_1_str);
    num_2 = std::stod(num_2_str);

    double result = 0;
    if (operation == '+') result = num_1 + num_2;
    else if (operation == '-') result = num_1 - num_2;
    else if (operation == '*') result = num_1 * num_2;
    else if (operation == '/' && num_2 != 0) result = num_1 / num_2;
    else std::cout << "Error!\n";

    printf("%f", result);
    
    return 0;
}