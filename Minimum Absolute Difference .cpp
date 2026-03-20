class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> res(n - k + 1, vector<int>(m - k + 1));

        for (int i = 0; i <= n-k; i++) {
            for (int j = 0; j <= m-k; j++) {
                set<int> st;

                for (int r = i; r <= i + k - 1; r++) {
                    for (int c = j; c <= j + k - 1; c++) {
                        st.insert(grid[r][c]);
                    }
                }

                if(st.size() == 1){
                    res[i][j] = 0;
                    continue;
                }

                int minDiff = INT_MAX;
                auto prev = st.begin();
                auto curr = next(prev);

                while (curr != st.end()) {
                    minDiff = min(minDiff, *curr - *prev);
                    prev = curr;
                    curr++;
                }

                res[i][j] = minDiff;
            }
        }
        return res;
    }
};
