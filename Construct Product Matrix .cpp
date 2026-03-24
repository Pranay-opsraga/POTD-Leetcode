class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int mod = 12345;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> res(n, vector<int>(m));

        long long product = 1LL;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                res[i][j] = product;
                product = (product * grid[i][j]) % mod;
            }
        }

        product = 1LL;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                res[i][j] = (res[i][j] * product) % mod;
                product = (product * grid[i][j]) % mod;
            }
        }
        return res;
    }
};
