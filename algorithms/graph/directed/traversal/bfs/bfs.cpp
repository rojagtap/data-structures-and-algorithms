#include<queue>
#include<iostream>
#include "../../../../../data_structures/graphs/graph.cpp"

using namespace std;


class DirectedGraph : public Graph {
public:
    DirectedGraph(const int nodes, const vector<vector<int>>& adjacency_list) : Graph(nodes, adjacency_list) {};

    vector<int> traverse() {
        vector<int> traversal;
        vector<bool> visited(nodes, false);
        for (int node = 0; node < nodes; ++node) {
            if (!visited[node]) {
                traverse(node, visited, traversal);
            }
        }

        return traversal;
    }

    vector<int> topological() {
        int indegree[nodes];
        memset(indegree, 0, nodes * sizeof(int));

        for (int node = 0; node < nodes; ++node) {
            for (int next : adjacency_list[node]) {
                ++indegree[next];
            }
        }

        queue<int> buffer;
        for (int node = 0; node < nodes; ++node) {
            if (!indegree[node]) {
                buffer.push(node);
            }
        }

        vector<int> traversal;
        while (!buffer.empty()) {
            int node = buffer.front(); buffer.pop();

            traversal.push_back(node);

            for (int next : adjacency_list[node]) {
                --indegree[next];
                if (!indegree[next]) {
                    buffer.push(next);
                }
            }
        }

        return traversal;
    }

    bool hasCycle() {
        return topological().size() != nodes;
    }

private:
    void traverse(const int from, vector<bool>& visited, vector<int>& traversal) {
        queue<int> buffer;
        buffer.push(from);
        visited[from] = true;

        while (!buffer.empty()) {
            int node = buffer.front(); buffer.pop();

            traversal.push_back(node);

            for (int next : adjacency_list[node]) {
                if (!visited[next]) {
                    buffer.push(next);
                    visited[next] = true;
                }
            }
        }
    }
};

int main() {
    const int nodes = 5;
    const vector<vector<int>> adjacency_list = {{}, {2, 3}, {1, 5, 6}, {1, 4, 7}, {3, 8}, {2}, {2}, {3, 8}, {4, 7}};
    DirectedGraph graph(nodes, adjacency_list);

    cout << "Directed graph:" << endl;
    vector<int> traversal = graph.traverse();
    for (auto& node : traversal) {
        cout << node << " ";
    }
    cout << endl;

    cout << "has cycle: " << graph.hasCycle() << endl;

    cout << "topological:" << endl;
    vector<int> topological = graph.topological();
    for (auto& node : topological) {
        cout << node << " ";
    }
    cout << endl;
    
    return 0;
}

