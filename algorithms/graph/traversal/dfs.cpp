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
                traverse(node, traversal, visited);
            }
        }

        return traversal;
    }

    bool hasCycle() {
        vector<bool> path(nodes, false);
        vector<bool> visited(nodes, false);
        for (int node = 0; node < nodes; ++node) {
            if (!visited[node] && hasCycle(node, visited, path)) {
                return true;
            }
        }

        return false;
    }

    vector<int> topological() {
        vector<int> traversal;
        vector<bool> visited(nodes, false);
        for (int node = 0; node < nodes; ++node) {
            if (!visited[node]) {
                topological(node, traversal, visited);
            }
        }

        reverse(traversal.begin(), traversal.end());
        return traversal;
    }

private:
    int nodes;
    vector<vector<int>> adjacency_list;

    void traverse(const int from, vector<int>& traversal, vector<bool>& visited) {
        visited[from] = true;
        traversal.push_back(from);

        for (auto& next : adjacency_list[from]) {
            if (!visited[next]) {
                traverse(next, traversal, visited);
            }
        }
    }

    bool hasCycle(const int from, vector<bool>& visited, vector<bool>& path) {
        path[from] = true;
        visited[from] = true;

        for (auto& next : adjacency_list[from]) {
            if (visited[next] && path[next]) {
                return true;
            } else if (!visited[next] && hasCycle(next, visited, path)) {
                return true;
            }
        }

        path[from] = false;
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


class UndirectedGraph {
public:
    UndirectedGraph(const int nodes, const vector<vector<int>>& adjacency_list) : nodes(nodes), adjacency_list(adjacency_list) {};

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

private:
    int nodes;
    vector<vector<int>> adjacency_list;

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

