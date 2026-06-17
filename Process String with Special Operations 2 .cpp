class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();
        long long L = 0;

        for (char ch : s) {
            if (ch == '#') {
                L = L * 2;
            } else if (ch == '%') {
                continue;
            } else if (ch == '*') {
                if (L > 0)
                    L--;
            } else {
                L++;
            }
        }

        if (k >= L)
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '#') {
                L = L / 2;
                if (k >= L)
                    k = k - L;
            } else if (s[i] == '*') {
                L++;
            } else if (s[i] == '%') {
                k = L - k - 1;
            } else {
                L--;
            }

            if (k == L)
                return s[i];
        }
        return '.';
    }
};
