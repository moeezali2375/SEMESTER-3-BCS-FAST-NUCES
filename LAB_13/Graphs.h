#include <iostream>
#include <queue>
#include <list>
#include <stack>
using namespace std;
class Graph
{
    int V;
    pair<int, list<int> > *array;
    bool isDirected;

public:
    Graph(int n);
    void TakeInput(int v, int w);
    void DFS(int start);
    void BFS(int start);
    bool Is_Connected(int n);
    bool isReachable(int u, int v);
    bool is_SC();
    bool is_cyclic();
    void print_graph();
};

Graph::Graph(int n)
{
    isDirected = true;
    V = n;
    array = new pair<int, list<int> >[V];
    for (int i = 0; i < V; i++)
    {
        array[i].first = i;
    }
}

void Graph::TakeInput(int v, int w)
{
    array[v].second.push_back(w);
}

void Graph::BFS(int start)
{
    queue<int> q;
    bool found[V];
    for (int i = 0; i < V; i++)
    {
        found[i] = false;
    }

    q.push(start);
    found[start] = true;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        cout << temp << " ";
        // found[temp] = true;
        for (list<int>::iterator it = array[temp].second.begin(); it != array[temp].second.end(); ++it)
        {
            if (found[*it] == false)
            {
                q.push(*it);
                found[*it] = true;
            }
        }
    }
}

void Graph::DFS(int start)
{
    stack<int> s;
    bool found[V];
    for (int i = 0; i < V; i++)
    {
        found[i] = false;
    }

    s.push(start);
    found[start] = true;
    while (!s.empty())
    {
        int temp = s.top();
        s.pop();
        cout << temp << " ";

        for (list<int>::iterator it = array[temp].second.begin(); it != array[temp].second.end(); ++it)
        {
            if (found[*it] == false)
            {
                s.push(*it);
                found[*it] = true;
            }
        }
    }
}

void Graph::print_graph()
{
    for (int i = 0; i < V; i++)
    {
        cout << array[i].first << ": ";
        for (list<int>::iterator it = array[i].second.begin(); it != array[i].second.end(); ++it)
        {
            cout << *it << "->";
        }
        cout << "NULL";
        cout << endl;
    }
    cout << "----------------------------------------------------------------";
    cout << endl;
}