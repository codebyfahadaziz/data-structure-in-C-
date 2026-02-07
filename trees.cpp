#include <iostream>
using namespace std;

// Maximum number of vertices in the graph
#define MAX 100

class Graph {
private:
    int V; // Number of vertices
    int adj[MAX][MAX]; // Adjacency matrix
    int front, rear; // For queue implementation
    int queue[MAX]; // Array implementation of queue
    int top; // For stack implementation
    int stack[MAX]; // Array implementation of stack
    
public:
    // Constructor
    Graph(int vertices) {
        V = vertices;
        front = rear = -1;
        top = -1;
        
        // Initialize adjacency matrix to 0 (no edges)
        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                adj[i][j] = 0;
            }
        }
    }
    
    // Queue operations
    void enqueue(int vertex) {
        if(rear == MAX-1) {
            cout << "Queue overflow!\n";
            return;
        }
        if(front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = vertex;
    }
    
    int dequeue() {
        if(front == -1 || front > rear) {
            cout << "Queue underflow!\n";
            return -1;
        }
        int vertex = queue[front];
        front++;
        return vertex;
    }
    
    bool isQueueEmpty() {
        return (front == -1 || front > rear);
    }
    
    // Stack operations
    void push(int vertex) {
        if(top == MAX-1) {
            cout << "Stack overflow!\n";
            return;
        }
        top++;
        stack[top] = vertex;
    }
    
    int pop() {
        if(top == -1) {
            cout << "Stack underflow!\n";
            return -1;
        }
        int vertex = stack[top];
        top--;
        return vertex;
    }
    
    bool isStackEmpty() {
        return (top == -1);
    }
    
    // Function to add an edge to the graph
    void addEdge(int v, int w) {
        adj[v][w] = 1; // For directed graph
    }
    
    // BFS traversal from a given source vertex
    void BFS(int startVertex) {
        // Create visited array
        int visited[MAX] = {0};
        
        // Reset queue
        front = rear = -1;
        
        // Mark the starting vertex as visited and enqueue it
        visited[startVertex] = 1;
        enqueue(startVertex);
        
        cout << "BFS starting from vertex " << startVertex << ": ";
        
        while(!isQueueEmpty()) {
            // Dequeue a vertex and print it
            int current = dequeue();
            cout << current << " ";
            
            // Get all adjacent vertices of the dequeued vertex
            for(int i = 0; i < V; i++) {
                // If there is an edge from current to i and i is not visited
                if(adj[current][i] == 1 && visited[i] == 0) {
                    visited[i] = 1;
                    enqueue(i);
                }
            }
        }
        cout << endl;
    }
    
    // DFS traversal from a given source vertex (iterative)
    void DFS(int startVertex) {
        // Create visited array
        int visited[MAX] = {0};
        
        // Reset stack
        top = -1;
        
        // Push the starting vertex
        push(startVertex);
        
        cout << "DFS starting from vertex " << startVertex << ": ";
        
        while(!isStackEmpty()) {
            // Pop a vertex from stack
            int current = pop();
            
            // If not visited, process it
            if(visited[current] == 0) {
                cout << current << " ";
                visited[current] = 1;
            }
            
            // Push all adjacent vertices that are not visited
            // We go in reverse order to maintain same order as recursive DFS
            for(int i = V-1; i >= 0; i--) {
                if(adj[current][i] == 1 && visited[i] == 0) {
                    push(i);
                }
            }
        }
        cout << endl;
    }
    
    // Recursive DFS helper function
    void DFSUtil(int v, int visited[]) {
        // Mark current vertex as visited and print it
        visited[v] = 1;
        cout << v << " ";
        
        // Recur for all vertices adjacent to this vertex
        for(int i = 0; i < V; i++) {
            if(adj[v][i] == 1 && visited[i] == 0) {
                DFSUtil(i, visited);
            }
        }
    }
    
    // DFS traversal using recursion
    void DFS_Recursive(int startVertex) {
        int visited[MAX] = {0};
        
        cout << "DFS Recursive starting from vertex " << startVertex << ": ";
        DFSUtil(startVertex, visited);
        cout << endl;
    }
};

int main() {
    // Create a graph with 4 vertices
    Graph g(4);
    
    // Add edges as shown in your code fragment
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    cout << "Graph with 4 vertices (0 to 3)" << endl;
    cout << "Edges: 0->1, 0->2, 1->2, 2->0, 2->3, 3->3" << endl;
    cout << "==============================================" << endl;
    
    // Test BFS from different starting vertices
    g.BFS(2);
    g.BFS(0);
    
    cout << "==============================================" << endl;
    
    // Test DFS from different starting vertices
    g.DFS(2);
    g.DFS(0);
    
    cout << "==============================================" << endl;
    
    // Test Recursive DFS
    g.DFS_Recursive(2);
    g.DFS_Recursive(0);
    
    cout << "\n\nExample with a larger graph (5 vertices):" << endl;
    cout << "==============================================" << endl;
    
    // Create another graph with 5 vertices
    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 3);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    
    g2.BFS(0);
    g2.DFS(0);
    g2.DFS_Recursive(0);
    
    return 0;
}
