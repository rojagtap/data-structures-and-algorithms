#include<queue>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


class DirectedGraph {
public:
    DirectedGraph(const int nodes, const vector<vector<int>>& adjacency_list) : nodes(nodes), adjacency_list(adjacency_list) {};

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
    int nodes;
    vector<vector<int>> adjacency_list;

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

class UndirectedGraph {
public:
    UndirectedGraph(const int nodes, const vector<vector<int>>& adjacency_list) : nodes(nodes), adjacency_list(adjacency_list) {};

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

    bool hasCycle() {
        vector<bool> visited(nodes, false);
        for (int node = 0; node < nodes; ++node) {
            if (!visited[node] && hasCycle(node, visited)) {
                return true;
            }
        }

        return false;
    }

private:
    int nodes;
    vector<vector<int>> adjacency_list;

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

    bool hasCycle(const int from, vector<bool>& visited) {
        queue<int> buffer;
        buffer.push(from);
        visited[from] = true;

        while (!buffer.empty()) {
            int node = buffer.front(); buffer.pop();

            for (int next : adjacency_list[node]) {
                if (!visited[next]) {
                    buffer.push(next);
                    visited[next] = true;
                } else if (next != node) {
                    return true;
                }
            }
        }

        return false;
    }
};


int main() {
    {
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
    }

    {
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
    }
    
    return 0;
}

