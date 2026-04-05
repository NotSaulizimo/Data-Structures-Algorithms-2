// Your First C++ Program

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

struct Edge
{
    int weight;
    int node_from;
    int node_to;
};

//MST
std::vector<Edge> mst;
std::vector<Edge> graph;

bool compareEdges(const Edge& e1, const Edge& e2)
{
    return e1.node_from < e2.node_from;
}
Edge createEdge( int node_from, int node_to, int weight)
{
    Edge e;
    e.weight = weight;
    e.node_from = node_from;
    e.node_to = node_to;
    std::cout << "Edge created: " << e.node_from << " -> " << e.node_to << " with weight " << e.weight << std::endl;
    return e;
}

std::vector<int> readValuesFromLine(std::ifstream& file)
{
    std::vector<int> values;
    std::string line;

    if (!std::getline(file, line))
    {
        std::cerr << "Error reading file: " << "values.txt" << std::endl;
        return values;
    }

    std::istringstream iss(line);
    int number;
    while (iss >> number)
    {
        values.push_back(number);
    }

    return values;
}

int main() {
    //Build a graph from a file
    std::ifstream file("values.txt");

        if (!file.is_open())
    {
        std::cerr << "Error opening file: " << "values.txt" << std::endl;
        return 1;
    }

    while(true)
    {
    std::vector<int> values = readValuesFromLine(file);

    if (values.empty()) {
        break;
    }
    Edge e = createEdge(values[0], values[1], values[2]);
    graph.push_back(e);
    }
    return 0;
}

int test()
{
    return 0;
}

