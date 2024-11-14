#include<bits/stdc++.h>

using namespace std;

class Graph {
public:
    Graph(const int nodes, const vector<vector<int>>& adjacency_list): nodes(nodes), adjacency_list(adjacency_list) {};

    virtual vector<int> traverse() = 0;
    virtual bool hasCycle() = 0;
    virtual vector<int> topological() = 0;
protected:
    int nodes;
    vector<vector<int>> adjacency_list;
};