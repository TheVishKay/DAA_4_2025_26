#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the minimum Hamiltonian cycle
int tspUtil(vector<vector<int>>& graph, int mask, int pos, vector<vector<int>>& dp) {
    if (mask == (1 << graph.size()) - 1 && graph[pos][0] != 0)
        return graph[pos][0];
    
    if (dp[mask][pos] != -1)
        return dp[mask][pos];
    
    int ans = INT_MAX;
    for (int city = 0; city < graph.size(); city++) {
        if ((mask & (1 << city)) == 0 && graph[pos][city] != 0) {
            int newAns = graph[pos][city] + tspUtil(graph, mask | (1 << city), city, dp);
            ans = min(ans, newAns);
        }
    }
    
    return dp[mask][pos] = ans;
}

// Function to solve the Traveling Salesman Problem
int tsp(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<vector<int>> dp((1 << n), vector<int>(n, -1));
    return tspUtil(graph, 1, 0, dp);
}

int main() {
    vector<vector<int>> graph = {
        {0, 10, 15, 20},
        {10, 0, 35, 25},
        {15, 35, 0, 30},
        {20, 25, 30, 0}
    };
    
    cout << "The minimum cost of the TSP is: " << tsp(graph) << endl;
    return 0;
}
