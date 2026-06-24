class Solution {
public:
    int MOD = 1e9 + 7;
    using ll = long long;
    int N, M;
    int dp[2001][2001][2];
    int solve(int ind, int prev, bool inc) {

        if (ind == N)
            return 1;

        ll result = 0;

        if (dp[ind][prev][inc] != -1)
            return dp[ind][prev][inc];

        if (inc) { // increasing
            for (int nv = prev + 1; nv <= M; nv++) {
                result = (result + solve(ind + 1, nv, false)) % MOD;
            }
        } else { // decreasing
            for (int nv = 1; nv < prev; nv++) {
                result = (result + solve(ind + 1, nv, true)) % MOD;
            }
        }
        return dp[ind][prev][inc] = result;
    }
    int zigZagArrays(int n, int l, int r) {

        N = n;
        M = r - l + 1;

        ll result = 0;
        memset(dp, -1, sizeof(dp));

        for (int sv = 1; sv <= M; sv++) {

            result = (result + solve(1, sv, true)) % MOD;

            result = (result + solve(1, sv, false)) % MOD;
        }
        return result;
    }
};

// Tabulation

class Solution {
public:
    int MOD = 1e9 + 7;
    using ll = long long;
    int zigZagArrays(int n, int l, int r) {

        int N = n;
        int M = r - l + 1;

        int dp[2001][2001][2];
        memset(dp, 0, sizeof(dp));

        for (int pv = 1; pv <= M; pv++) {
            dp[N][pv][0] = 1;
            dp[N][pv][1] = 1;
        }

        for (int i = N - 1; i >= 1; i--) {
            for (int pv = 1; pv <= M; pv++) {

                for (int nv = pv + 1; nv <= M; nv++) {
                    dp[i][pv][1] = (dp[i][pv][1] + dp[i + 1][nv][0]) % MOD;
                }
                for (int nv = 1; nv < pv; nv++) {
                    dp[i][pv][0] = (dp[i][pv][0] + dp[i + 1][nv][1]) % MOD;
                }
            }
        }
        ll result = 0;
        for (int sv = 1; sv <= M; sv++) {

            result = (result + dp[1][sv][1]) % MOD;

            result = (result + dp[1][sv][0]) % MOD;
        }
        return result;
    }
};


// Cumutative sum

class Solution {
public:
    int MOD = 1e9 + 7;
    using ll = long long;
    int zigZagArrays(int n, int l, int r) {

        int N = n;
        int M = r - l + 1;

        int dp[2001][2001][2];
        memset(dp, 0, sizeof(dp));

        for (int pv = 1; pv <= M; pv++) {
            dp[N][pv][0] = 1;
            dp[N][pv][1] = 1;
        }

        for (int i = N - 1; i >= 1; i--) {

            vector<ll>cumsum1(M + 1, 0);
            vector<ll>cumsum0(M + 1, 0);

            for (int val = 1; val <= M; val++) {
                cumsum1[val] = (cumsum1[val - 1] + dp[i+1][val][1]) % MOD;
                cumsum0[val] = (cumsum0[val - 1] + dp[i+1][val][0]) % MOD;
            }
            for (int pv = 1; pv <= M; pv++) {

                dp[i][pv][1] = (cumsum0[M] - cumsum0[pv] + MOD) % MOD;
                dp[i][pv][0] = cumsum1[pv - 1];
            }
        }
        ll result = 0;
        for (int sv = 1; sv <= M; sv++) {

            result = (result + dp[1][sv][1]) % MOD;

            result = (result + dp[1][sv][0]) % MOD;
        }
        return result;
    }
};
