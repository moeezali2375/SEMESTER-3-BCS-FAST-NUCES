#include <iostream>
#include <stack>
using namespace std;
int main()
{
    cout << "Creating stack!" << endl;
    stack<int> a;
    a.push(5);
    int temp = a.top();
    a.pop();
    cout << a.empty()<<"hehe";
}