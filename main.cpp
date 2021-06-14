#include <iostream>
#include <sstream>

bool INPUT_ERROR = false;

double GetResult(double num_1, double num_2, char operation)
{
    INPUT_ERROR = false;
    double result = 0;

    if (operation == '+') result = num_1 + num_2;
    else if (operation == '-') result = num_1 - num_2;
    else if (operation == '*') result = num_1 * num_2;
    else if (operation == '/' && num_2 != 0) result = num_1 / num_2;
    else INPUT_ERROR = true;

    return result;
}

int main()
{
    do
    {
        std::string buffer;
        std::cout << "Please enter the expression <Num1><Operation><Num2> or type 'q' to exit:\n";
        std::cin >> buffer;

        if (buffer == "q") break;

        std::stringstream buf(buffer);
        double num_1 = 0;
        double num_2 = 0;
        char operation;

        buf >> num_1 >> operation >> num_2;
        double result = GetResult(num_1, num_2, operation);

        if (!INPUT_ERROR) printf("Result: %f\n", result);
        else std::cout << "Bad input or division on zero!\n";

    } while (true);

    std::cout << "Exit program\n";

    return 0;
}