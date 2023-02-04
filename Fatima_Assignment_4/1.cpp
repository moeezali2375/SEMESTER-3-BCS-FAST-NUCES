#include <iostream>
#include <math.h>
using namespace std;

int reverseDigits(int columns, int p)
{
    if (p <= 0)
        return columns;
    int r = columns % 10;
    int multiple = pow(10, p);
    r *= multiple;
    int temp = reverseDigits(columns / 10, p - 1);
    return temp + r;
}

int main()
{
    int columns;
    cout << "Enter the Number you want to reverse: ";
    cin >> columns;
    int power;
    cout << "Enter the digits: ";
    cin >> power;
    cout << "The reversed number is: " << endl;
    cout << reverseDigits(columns, power - 1);
}