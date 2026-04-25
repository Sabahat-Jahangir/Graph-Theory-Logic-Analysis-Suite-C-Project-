#include <iostream>
#include <queue>
using namespace std;

#define MAX 100

class Graph {
private:
    int vertices;
    int adjMatrix[MAX][MAX];

public:
    // Constructor to initialize the graph with given vertices
    Graph(int v) {
        vertices = v;
        // Initialize adjacency matrix
        for (int i = 0; i < vertices; ++i) {
            for (int j = 0; j < vertices; ++j) {
                adjMatrix[i][j] = 0; // Initialize all elements to 0
            }
        }
    }

    // Function to add an edge between vertices v and w
    void addEdge(int v, int w) {
        adjMatrix[v][w] = 1;
        adjMatrix[w][v] = 1; // Since it's an undirected graph
    }

    // Function to check if the graph is bipartite
    bool isBipartite() {
        int color[MAX];
        for (int i = 0; i < vertices; ++i) {
            color[i] = -1; // Initialize color array
        }

        // Start BFS from each vertex if its color is not assigned
        for (int i = 0; i < vertices; ++i) {
            if (color[i] == -1) {
                if (!bfs(i, color)) {
                    return false; // Graph is not bipartite
                }
            }
        }
        return true; // Graph is bipartite
    }

    // BFS for checking bipartiteness
    bool bfs(int src, int color[]) {
        queue<int> q;
        q.push(src);
        color[src] = 1; // Color the source vertex

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v = 0; v < vertices; ++v) {
                if (adjMatrix[u][v] && color[v] == -1) {
                    color[v] = 1 - color[u]; // Assign alternate color to this adjacent vertex
                    q.push(v);
                } else if (adjMatrix[u][v] && color[v] == color[u]) {
                    // Conflicting vertices found
                    cout << "Vertices " << u << " and " << v << " are causing conflict." << endl;
                    return false;
                }
            }
        }
        return true;
    }
};

int main() {
	cout << "\t\t                   ------------------------------" << endl;
	cout << "\t\t                  | WELCOME TO OUR CODE PALACE   |" << endl;
	cout << "\t\t                   ------------------------------" << endl;
	cout << endl;
    
    cout << "\t\t         -----------------------------------------------------------------" << endl;
	cout << "\t\t        | OUR CODE WILL DETERMINE WHETHER THE GRAPH IS Bipartite or not.  |" << endl;
	cout << "\t\t         -----------------------------------------------------------------" << endl;
	cout << endl;
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;

    Graph g(v); // Create a graph with v vertices

    cout << "Enter the number of edges: ";
    cin >> e;

    cout << "Enter the edges (vertex1 vertex2):" << endl;
    // Input the edges
    for (int i = 0; i < e; ++i) {
        int v1, v2;
        cin >> v1 >> v2;
        g.addEdge(v1, v2); // Add edges to the graph
    }

    // Check if the graph is bipartite
    if (g.isBipartite()) {
        cout << "Graph is bipartite." << endl;
    } else {
        cout << "Graph is not bipartite." << endl;
    }

    return 0;
}

