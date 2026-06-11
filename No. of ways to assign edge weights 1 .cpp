class Solution {
public:
    long long mod = 1e9+7;
    long long power(long long base , long long expo){
          long long res = 1;
          while(expo){
             if(expo & 1) res = (res * base) % mod;
             base = (base * base) % mod;
             expo >>= 1;  
          }
          return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size()+1;

        vector<vector<int>> adj(n + 1);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        queue<pair<int, int>> q;
        q.push({1, 0});

        vector<int> vis(n + 1);
        vis[1] = 1;
        int maxdepth = 0;

        while (!q.empty()) {
            auto [node, depth] = q.front();
            q.pop();
            maxdepth = max(maxdepth, depth);

            for (int it : adj[node]) {
                if (!vis[it]) {
                    vis[it] = 1;
                    q.push({it , depth+1});
                }
            }
        }
        return (int)power(2 , maxdepth-1);
    }
};
