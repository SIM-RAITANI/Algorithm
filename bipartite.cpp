#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, -1); // -1: uncolored, 0/1: colors
    
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            queue<int> q;
            q.push(i);
            color[i] = 0;
            
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                
                for (int neighbor : graph[node]) {
                    if (color[neighbor] == -1) {
                        color[neighbor] = color[node] ^ 1; // Flip color
                        q.push(neighbor);
                    } else if (color[neighbor] == color[node]) {
                        return false; // Same color found
                    }
                }
            }
        }
    }
    return true;
}

int main() {
    // Example 1: Bipartite graph (can be divided into two colors)
    vector<vector<int>> graph1 = {{1,3}, {0,2}, {1,3}, {0,2}};
    cout << "Graph 1 is " << (isBipartite(graph1) ? "bipartite" : "not bipartite") << endl;
    
    // Example 2: Non-bipartite graph (odd-length cycle)
    vector<vector<int>> graph2 = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    cout << "Graph 2 is " << (isBipartite(graph2) ? "bipartite" : "not bipartite") << endl;
    
    return 0;
}