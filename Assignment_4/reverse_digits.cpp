#include <iostream>
#include <math.h>
using namespace std;

int reverse_digits(int number, int p)
{
    if (p == 0)
    {
        return number;
    }
    else
    {
        int reverse = number % 10;
        int multiple = pow(10, p);
        reverse *= multiple;
        int temp = reverse_digits(number / 10, p - 1);
        return temp + reverse;
    }
}

int main()
{
    cout << "Enter the number you want to reverse: ";
    int number;
    cin >> number;
    int digits = 0;
    int number2 = number;
    while (number2 > 0)
    {
        digits++;
        number2 /= 10;
    }
    cout << "Reversed Digits are: " << endl;
    cout << reverse_digits(number, digits - 1);
}