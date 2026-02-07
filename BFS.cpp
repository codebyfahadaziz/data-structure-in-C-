#include <bits/stdc++.h>
using namespace std;

// Graph represented as adjacency list
vector<vector<int>> adj;

// BFS function
void BFS(int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    cout << "BFS Traversal: ";
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    cout << endl;
}

// DFS function (recursive)
void DFS(int node, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";

    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, visited);
        }
    }
}

void DFS(int start) {
    int n = adj.size();
    vector<bool> visited(n, false);
    cout << "DFS Traversal: ";
    DFS(start, visited);
    cout << endl;
}

int main() {
    // Number of nodes
    int n = 5;
    adj.resize(n);

    // Add edges (undirected graph)
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 4};
    adj[3] = {1};
    adj[4] = {1, 2};

    // Perform BFS starting from node 0
    BFS(0);

    // Perform DFS starting from node 0
    DFS(0);

    return 0;
}