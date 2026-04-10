class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> prices(n, 1e9);
        prices[src] = 0;

        for (int i = 0; i <= k; i++) {
            vector<int> temp = prices;
            for (auto& f : flights) {
                int u = f[0];
                int v = f[1];
                int w = f[2];
                if (prices[u] != 1e9) {
                    temp[v] = min(temp[v], prices[u] + w);
                }
            }
            prices = temp;
        }

        return (prices[dst] == 1e9) ? -1 : prices[dst];
    }
};