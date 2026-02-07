#include <iostream>
using namespace std;

#define MAX 10

// ---------------- Queue Class ----------------
class Queue {
    int arr[MAX];
    int front, rear;

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1;
    }

    void enqueue(int x) {
        if (rear == MAX - 1)
            return;
        if (front == -1)
            front = 0;
        arr[++rear] = x;
    }

    int dequeue() {
        int x = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return x;
    }
};

// ---------------- Graph Class ----------------
class Graph {
    int V;
    int adj[MAX][MAX];   // adjacency matrix

public:
    Graph(int v) {
        V = v;
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                adj[i][j] = 0;
    }

    void addEdge(int u, int v) {
        adj[u][v] = 1;   // directed edge
    }

    // -------- Display Graph --------
    void displayGraph() {
        cout << "\nAdjacency Matrix:\n   ";
        for (int i = 0; i < V; i++)
            cout << i << " ";
        cout << endl;

        for (int i = 0; i < V; i++) {
            cout << i << ": ";
            for (int j = 0; j < V; j++) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
    }

    // -------- DFS --------
    void DFSUtil(int v, bool visited[]) {
        visited[v] = true;
        cout << v << " ";

        for (int i = 0; i < V; i++) {
            if (adj[v][i] == 1 && !visited[i]) {
                DFSUtil(i, visited);
            }
        }
    }

    void DFS(int start) {
        bool visited[MAX] = {false};
        cout << "\nDFS Traversal: ";
        DFSUtil(start, visited);
        cout << endl;
    }

    // -------- BFS --------
    void BFS(int start) {
        bool visited[MAX] = {false};
        Queue q;

        visited[start] = true;
        q.enqueue(start);

        cout << "\nBFS Traversal: ";

        while (!q.isEmpty()) {
            int v = q.dequeue();
            cout << v << " ";

            for (int i = 0; i < V; i++) {
                if (adj[v][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.enqueue(i);
                }
            }
        }
        cout << endl;
    }
};

// ---------------- Main ----------------
int main() {
    Graph g(4);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.displayGraph();

    int start = 2;
    g.DFS(start);
    g.BFS(start);

    return 0;
}
