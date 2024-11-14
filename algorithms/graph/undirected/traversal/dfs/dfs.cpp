#include<iostream>
#include "../../../../../data_structures/graphs/graph.cpp"

using namespace std;


class UndirectedGraph : public Graph {
public:
    UndirectedGraph(const int nodes, const vector<vector<int>>& adjacency_list) : Graph(nodes, adjacency_list) {};

    vector<int> traverse() {
        vector<int> traversal;
        vector<bool> visited(nodes, false);
        for (int node = 0; node < nodes; ++node) {
            if (!visited[node]) {
                traverse(node, traversal, visited);
            }
        }

        return traversal;
    }

    bool hasCycle() {
        vector<bool> visited(nodes, false);
        for (int node = 0; node < nodes; ++node) {
            if (!visited[node] && hasCycle(node, visited)) {
                return true;
            }
        }

        return false;
    }

    vector<int> topological() {
        throw "Not Implemented";
    }

private:
    void traverse(const int from, vector<int>& traversal, vector<bool>& visited) {
        visited[from] = true;
        traversal.push_back(from);

        for (auto& next : adjacency_list[from]) {
            if (!visited[next]) {
                traverse(next, traversal, visited);
            }
        }
    }

    bool hasCycle(const int from, vector<bool>& visited) {
        visited[from] = true;

        for (auto& next : adjacency_list[from]) {
            if (next != from && visited[next]) {
                return true;
            } else if (!visited[next] && hasCycle(next, visited)) {
                return true;
            }
        }

        return false;
    }

    void topological(const int from, vector<int>& traversal, vector<bool>& visited) {
        visited[from] = true;

        for (auto& next : adjacency_list[from]) {
            if (!visited[next]) {
                topological(next, traversal, visited);
            }
        }

        traversal.push_back(from);
    }
};


int main() {
    const int nodes = 5;
    const vector<vector<int>> adjacency_list = {{1}, {0, 2, 4}, {1, 3}, {2, 4}, {1, 3}};
    UndirectedGraph graph(nodes, adjacency_list);

    cout << "Undirected graph:" << endl;
    vector<int> traversal = graph.traverse();
    for (auto& node : traversal) {
        cout << node << " ";
    }
    cout << endl;

    cout << "has cycle: " << graph.hasCycle() << endl;

    return 0;
}