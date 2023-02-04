#include "stacks.h"
#include "doubly_list.h"
#include <iostream>
using namespace std;
int main()
{
    Stack<doubly_list<char> > undo(4);
    doubly_list<char> a;
    doubly_list<char>::iterator j = a.begin();
    a.insert(j, 'a');
    undo.push(a);
    a.insert(j, 'b');
    undo.push(a);
    a.insert(j, 'c');
    undo.push(a);
    a.display();
    cout << endl;
    undo.topp(a);
    undo.pop();
    a.display();
    cout << endl;
    char aa;
    cin>>aa;
}
// for (int i = 0; i < 3; i++)
// {
//     undo.topp(a);
//     undo.pop();
//     a.display();
//     cout << endl;
// }
// doubly_list<char> a;
// doubly_list<char> b;
// doubly_list<char>::iterator j = a.begin();
// a.insert(j, 'a');
// a.insert(j, 'b');
// a.insert(j, 'c');
// a.display();
// cout << endl;
// b = a;
// b.display();
// cout << endl;
// a.insert(j, 'c');
// a.display();
// cout << endl;
// b.display();
// }
