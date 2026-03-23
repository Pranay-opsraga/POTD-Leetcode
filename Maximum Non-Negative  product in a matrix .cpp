class Solution {
public:
    long long maxProductPath(vector<vector<int>>& grid) {
        long long MOD = 1e9+7;
        long long n = grid.size();
        long long m = grid[0].size();
        vector<vector<long long>> maxVal(n, vector<long long>(m));
        vector<vector<long long>> minVal(n, vector<long long>(m));

        maxVal[0][0] = minVal[0][0] = grid[0][0];

        for (int i = 1; i < n; i++) {
            maxVal[i][0] = minVal[i][0] = maxVal[i - 1][0] * grid[i][0];
        }

        for (int j = 1; j < m; j++) {
            maxVal[0][j] = minVal[0][j] = maxVal[0][j - 1] * grid[0][j];
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                long long val = grid[i][j];

                long long tmax = maxVal[i - 1][j] * val;
                long long tmin = minVal[i - 1][j] * val;
                long long lmax = maxVal[i][j - 1] * val;
                long long lmin = minVal[i][j - 1] * val;

                maxVal[i][j] = max({tmax, tmin, lmax, lmin});
                minVal[i][j] = min({tmax, tmin, lmax, lmin});
            }
        }
        long long ans = maxVal[n - 1][m - 1];

        if (ans < 0)
            return -1;
        return ans % MOD;
    }
};
