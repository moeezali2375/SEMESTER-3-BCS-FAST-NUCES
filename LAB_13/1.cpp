#include <iostream>
#include "Graphs.h"
using namespace std;
int main()
{

    int a = 32;
    float b = 0.5;
    a += b;
    cout << a;
    // Graph directed_graph(4);

    // directed_graph.TakeInput(0, 1);
    // directed_graph.TakeInput(0, 2);
    // directed_graph.TakeInput(1, 2);
    // directed_graph.TakeInput(2, 0);
    // directed_graph.TakeInput(2, 3);
    // directed_graph.TakeInput(3, 3);
    // directed_graph.print_graph();

    // directed_graph.BFS(2);
    // cout << endl;
    // directed_graph.DFS(2);
    // cout << endl;

    // int choice = 0;
    // do
    // {
    //     cout << "0. Exit" << endl;
    //     cout << "1. Insert" << endl;
    //     cout << "2. Insert" << endl;
    //     cout << "3. Print" << endl;
    //     cin >> choice;
    //     if (choice == 0)
    //     {
    //         cout << EXIT_SUCCESS;
    //         break;
    //     }
    //     else if (choice == 1)
    //     {
    //         int v;
    //         int w;
    //         cout << "Enter the vertex number: ";
    //         cin >> v;
    //         cout << "Enter the adjoining vertex number: ";
    //         cin >> w;
    //         directed_graph.TakeInput(v, w);
    //     }
    //     else if (choice == 3)
    //     {
    //         cout << "Graph is: " << endl;
    //         directed_graph.print_graph();
    //     }
    // } while (96);
}