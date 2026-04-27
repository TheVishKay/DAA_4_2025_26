#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// Function to find the shortest path from source to all other vertices using Dijkstra's algorithm
void dijkstra(vector<vector<pair<int, int>>>& graph, int src) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    dist[src] = 0;
    pq.push({0, src});
    
    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        
        if (d > dist[u])
            continue;
        
        for (auto& edge : graph[u]) {
            int v = edge.first;
            int weight = edge.second;
            
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < n; i++) {
        cout << i << "\t\t" << dist[i] << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<pair<int, int>>> graph(V);
    
    // Adding edges to the graph
    graph[0].push_back({1, 9});
    graph[0].push_back({3, 4});
    graph[0].push_back({2, 14});
    graph[1].push_back({2, 2});
    graph[1].push_back({3, 11});
    graph[2].push_back({3, 7});
    graph[3].push_back({4, 6});
    
    dijkstra(graph, 0);
    return 0;
}
