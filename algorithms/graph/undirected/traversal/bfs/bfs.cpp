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

    vector<int> topological() {
        throw "Not Implemented";
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