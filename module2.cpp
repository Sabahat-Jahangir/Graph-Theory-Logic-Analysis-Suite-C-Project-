#include <iostream>
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

    // Function to check if the graph is connected
    bool isConnected() {
        bool visited[MAX];
        for (int i = 0; i < vertices; ++i) {
            visited[i] = false; // Initialize visited array to false
        }

        int count = 0;
        // Start DFS from vertex 0 and count visited vertices
        dfs(0, visited, count);

        return count == vertices; // Check if all vertices were visited
    }

    // Depth First Search to check connectivity
    void dfs(int v, bool visited[], int& count) {
        visited[v] = true; // Mark vertex v as visited
        count++; // Increment count of visited vertices
        for (int i = 0; i < vertices; ++i) {
            // If there's an edge between v and i and i is not visited, visit i
            if (adjMatrix[v][i] && !visited[i]) {
                dfs(i, visited, count); // Recursive call for vertex i
            }
        }
    }

    // Function to check if there is a path between two vertices
    bool hasPath(int src, int dest) {
        bool visited[MAX];
        for (int i = 0; i < vertices; ++i) {
            visited[i] = false; // Initialize visited array to false
        }

        // Start DFS from source vertex
        return dfsForPath(src, dest, visited);
    }

    // Depth First Search to find a path between two vertices
    bool dfsForPath(int v, int dest, bool visited[]) {
        if (v == dest) {
            return true; // Path found
        }

        visited[v] = true; // Mark vertex v as visited
        for (int i = 0; i < vertices; ++i) {
            // If there's an edge between v and i and i is not visited, visit i
            if (adjMatrix[v][i] && !visited[i]) {
                if (dfsForPath(i, dest, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

    // Function to check graph properties (walk, closed walk, circuit, simple circuit, path, or simple path)
    void checkGraph(int src, int dest) {
        if (!isConnected()) {
            cout << "Graph is not connected." << endl;}
            
        

        bool isWalk = hasPath(src, dest);
        bool isClosedWalk = (isWalk && src == dest);
        bool isCircuit = (isWalk && isClosedWalk);
        bool isSimpleCircuit = (isCircuit && isSimple(src, dest));
        bool isSimplePath = (isWalk && !isCircuit && isSimple(src, dest));

        if (isSimpleCircuit) {
            cout << "Graph is a simple circuit." << endl;
        } else if (isCircuit) {
            cout << "Graph is a circuit." << endl;
        } else if (isSimplePath) {
            cout << "Graph is a simple path." << endl;
        } else if (isWalk) {
            cout << "Graph is a walk." << endl;
        } else {
            cout << "Graph is not a walk, closed walk, circuit, simple circuit, path, or simple path." << endl;
        }
    }

    // Function to check if the path between src and dest is simple
    bool isSimple(int src, int dest) {
        int count = 0;
        for (int i = 0; i < vertices; ++i) {
            if (adjMatrix[src][i] == 1) {
                count++;
            }
        }
        return count == 1;
    }
};
// Function to set text color
void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}
int main() {
	setColor(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "\t\t                                                 -----------------------------" << endl;
	cout << "\t\t                                                | WELCOME TO OUR CODE PALACE  |" << endl;
	cout << "\t\t                                                 -----------------------------" << endl;
	cout << endl;

    cout << "\t\t         -------------------------------------------------------------------------------------------------------------" << endl;
	cout << "\t\t        | OUR CODE WILL determine if the graph is a walk, closed walk, circuit, simple circuit, path or simple path.  |" << endl;
	cout << "\t\t         -------------------------------------------------------------------------------------------------------------" << endl;
	cout << endl;
    int v, e, src, dest;
    setColor(FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_GREEN);
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

    cout << "Enter source and destination vertices for path checking: ";
    cin >> src >> dest;

    // Perform graph property check
    g.checkGraph(src, dest); // Check graph properties

    return 0;
}

