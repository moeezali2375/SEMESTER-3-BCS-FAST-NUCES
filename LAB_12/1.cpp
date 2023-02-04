#include <iostream>
#include <unordered_map>
#include <string>
#include <list>
#include <fstream>
class graph
{
private:
    int **Matrix;
    int vertices;
    bool isDirected;

public:
    graph()
    {
        this->vertices = 0;
        this->isDirected = 0;
        this->Matrix = nullptr;
    }
    graph(int TVertices, bool direction)
    {
        this->isDirected = direction;
        this->vertices = TVertices;
        this->Matrix = new int *[this->vertices];
        for (int i = 0; i < vertices; i++)
        {
            this->Matrix[i] = new int[this->vertices];
        }
        for (int i = 0; i < vertices; i++)
            for (int j = 0; j < vertices; j++)
                this->Matrix[i][j] = 0;
    }
    graph(const graph &obj) { ; }
    graph(std::string fname)
    {
        std::ifstream fin(fname);
        fin >> vertices;
        vertices++;
        fin >> isDirected;
        this->Matrix = new int *[vertices];
        for (int i = 0; i < vertices; i++)
            this->Matrix[i] = new int[vertices];
        for (int i = 0; i < this->vertices; i++)
            for (int j = 0; j < this->vertices; j++)
                this->Matrix[i][j] = 0;
        fin.close();
        int curr_row = 0;
        int curr_col = 0;
        char garbchar = 0;
        fin.open(fname);
        if (!fin)
            std::cout << "\nUnable to Open File \n";
        else
            while (!fin.eof())
            {
                fin >> curr_row;
                fin >> curr_col;
                fin >> curr_row;
                while (curr_row < vertices && !fin.eof())
                {
                    fin >> std::noskipws >> garbchar;
                    if (garbchar == ' ')
                    {
                        fin >> curr_col;
                        this->Matrix[curr_row][curr_col] = 1;
                    }
                    else
                        fin >> curr_row;
                }
            }
        fin.close();
    }
    bool addEdge(int u, int v)
    {
        if (vertices > 0 && u < vertices && v < vertices)
        {
            this->Matrix[u][v] = 1;
            if (!isDirected)
                this->Matrix[v][u] = 1;
            return true;
        }
        return false;
    }
    bool removeEdge(int u, int v)
    {
        if (vertices > 0 && u < vertices && v < vertices)
        {
            this->Matrix[u][v] = 0;
            if (!isDirected)
                this->Matrix[v][u] = 0;
            return true;
        }
        return false;
    }
    bool isConnected(int x, int y);
    int getIndegree(int Vertex)
    {
        int count = 0;
        for (int i = 0; i < this->vertices; i++)
            if (this->Matrix[i][Vertex] == 1)
                count++;
        return count;
    }
    int getOutdegree(int Vertex)
    {
        int count = 0;
        for (int i = 0; i < this->vertices; i++)
            if (this->Matrix[Vertex][i] == 1)
                count++;
        return count;
    }
    void printAllAdjc()
    {
        std::cout << "The Adjacent Vertices Are Below \n";
        for (int i = 0; i < this->vertices; i++)
        {
            for (int j = 0; j < this->vertices; j++)
                if (this->Matrix[i][j] == 1)
                    std::cout << " ( " << i << " , " << j << " ) ";
            std::cout << std::endl;
        }
    }
    bool isComplete(); // is every node connected to any other node
    void printGraph()
    {
        for (int i = 0; i < vertices; i++)
        {
            for (int j = 0; j < vertices; j++)
                std::cout << " ( " << i << " , " << j << " ) ";
            std::cout << std::endl;
        }
    }
    ~graph()
    {
        if (this->vertices > 0)
            for (int i = 0; i < this->vertices; i++)
                delete[] this->Matrix[i];
        delete[] this->Matrix;
    }
};
int main()
{
    std::string filename;
    std::cout << "enter file name >> ";
    std::cin >> filename;
    filename = filename + ".txt";
    std::cout << "\nCreating Graph From file \n\n";
    graph G(filename);
    G.printGraph();
    std::cout << "\n\n";
    G.printAllAdjc();
}