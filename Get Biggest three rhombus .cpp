class Solution {
public:

    void add(vector<int>& best, int val)
    {
        best.push_back(val);

        sort(best.begin(), best.end(), greater<int>());

        best.erase(unique(best.begin(), best.end()), best.end());

        if(best.size() > 3)
            best.pop_back();
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        vector<int> best;

        for(int r = 0; r < n; r++)
        {
            for(int c = 0; c < m; c++)
            {
                add(best, grid[r][c]); // size 0 rhombus

                int k = 1;

                while(r-k >= 0 && r+k < n && c-k >= 0 && c+k < m)
                {
                    int sum = 0;

                    int i = r-k, j = c;

                    // top -> right
                    while(i < r && j < c+k)
                    {
                        sum += grid[i][j];
                        i++; j++;
                    }

                    // right -> bottom
                    while(i < r+k && j > c)
                    {
                        sum += grid[i][j];
                        i++; j--;
                    }

                    // bottom -> left
                    while(i > r && j > c-k)
                    {
                        sum += grid[i][j];
                        i--; j--;
                    }

                    // left -> top
                    while(i > r-k && j < c)
                    {
                        sum += grid[i][j];
                        i--; j++;
                    }

                    add(best, sum);

                    k++;
                }
            }
        }

        return best;
    }
};
