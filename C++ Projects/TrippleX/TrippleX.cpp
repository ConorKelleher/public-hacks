#include <iostream>

int main()
{
    std::cout << "You're going to be murdered if you can't break into this house!";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "You need to enter the correct code to continue...!";
    std::cout << std::endl;

    int a = 4;
    int b = 7;
    int c = 17;

    a = 7;

    int sum = a + b + c;
    int product = a * b * c;

    std::cout << sum << std::endl;
    std::cout << product << std::endl;

    return 0;
}