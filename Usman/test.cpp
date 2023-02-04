#include <iostream>
using namespace std;
class a
{
    int A;

public:
    a(int data = 0)
    {
        A = data;
    }
    void print()
    {
        cout << "A data" << A << endl;
    }
};
class b
{
    int B;
};
class c
{
    int C;
};
class d : public a, public c, public b
{
public:
    d(int date) : a(date)
    {
        ;
    }
    void print()
    {
        cout << "data of a: " << a::a
    }
};

class Employee
{
    public:
    Employee(int d, int m, int y, char *f_n, char *l_n, char *dept_n, char *dept_I) : date(d, m, y) : name(f_n, l_n) : department(dept_n, dept_I)
    {
        cout << "Yousaf wese idher kuch likhnay ki zrorat nahi hai";
    }
};
