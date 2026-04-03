class Solution {
public:
    vector<vector<int>> dp;
    int countwalls(vector<int>& walls, int l, int r) {
        int left = lower_bound(walls.begin(), walls.end(), l) - walls.begin();
        int right = upper_bound(walls.begin(), walls.end(), r) - walls.begin();

        return right - left;
    }
    int solve(vector<int>& walls, vector<int>& robots,
              vector<pair<int, int>>& roboDist, vector<pair<int, int>>& range,
              int i, int predir) {
        if (i == roboDist.size())
            return 0;

        if(dp[i][predir] != -1) return dp[i][predir];    

        int leftStart = range[i].first;

        if (predir == 1 && i > 0) {
            leftStart = max(leftStart, range[i - 1].second + 1);
        }

        int leftcount = countwalls(walls, leftStart, roboDist[i].first) +
                        solve(walls, robots, roboDist, range, i + 1, 0);

        int rightcount = countwalls(walls, roboDist[i].first, range[i].second) +
                         solve(walls, robots, roboDist, range, i + 1, 1);

        return dp[i][predir] = max(leftcount, rightcount);
    }
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {
        int n = robots.size();

        vector<pair<int, int>> roboDist;
        vector<pair<int, int>> range(n);

        for (int i = 0; i < n; i++) {
            roboDist.push_back({robots[i], distance[i]});
        }

        sort(roboDist.begin(), roboDist.end());

        sort(walls.begin(), walls.end());

        for (int i = 0; i < n; i++) {
            int pos = roboDist[i].first;
            int d = roboDist[i].second;

            int leftLimit = (i == 0) ? 1 : roboDist[i - 1].first + 1;
            int rightLimit = (i == n - 1) ? 1e9 : roboDist[i + 1].first - 1;
            int L = max(leftLimit, pos - d);
            int R = min(rightLimit, pos + d);

            range[i] = {L, R};
        }
        dp.assign(n, vector<int>(2, -1));
        return solve(walls, robots, roboDist, range, 0, 0);
    }
};
