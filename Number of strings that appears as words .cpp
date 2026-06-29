class Solution {
public:
    long long MOD = 1e9 + 7;
    long long BASE = 31;
    int numOfStrings(vector<string>& patterns, string word) {
        int n = word.size();

        vector<long long> power(n + 1);
        power[0] = 1;
        for (int i = 1; i <= n; i++) {
            power[i] = (power[i - 1] * BASE) % MOD;
        }

        vector<long long> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = (prefix[i] * BASE + (word[i] - 'a' + 1)) % MOD;
        }

        int ans = 0;

        for (string& pat : patterns) {
            int m = pat.size();

            long long pathash = 0;
            for (char c : pat) {
                pathash = (pathash * BASE + (c - 'a' + 1)) % MOD;
            }

            bool found = false;

            for (int i = 0; i + m <= n; i++) {

                long long curr =
                    (prefix[i + m] - prefix[i] * power[m] % MOD + MOD) % MOD;

                if (curr == pathash) {
                    if (word.substr(i, m) == pat) {
                        found = true;
                        break;
                    }
                }
            }
            if (found == true)
                ans++;
        }
        return ans;
    }
};
