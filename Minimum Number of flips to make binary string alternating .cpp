class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;
        int cnt1 = 0;
        int cnt2 = 0;
        int ans = INT_MAX;

        for (int i = 0; i < 2 * n; i++) {
            if (i & 1) {
                if (t[i] == '0')
                    cnt1++;
                else
                    cnt2++;
            } else {
                if (t[i] == '1')
                    cnt1++;
                else
                    cnt2++;
            }

            if (i >= n) {
                int j = i - n;

                if (j & 1) {
                    if (t[j] == '0')
                        cnt1--;
                    else
                        cnt2--;
                } else {
                    if (t[j] == '1')
                        cnt1--;
                    else
                        cnt2--;
                }
            }

            if (i >= n - 1)
                ans = min(ans, min(cnt1, cnt2));
        }
        return ans;
    }
};
