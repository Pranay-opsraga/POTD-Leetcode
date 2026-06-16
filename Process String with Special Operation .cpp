class Solution {
public:
    string processStr(string s) {
        int n = s.size();
        string res;
        for (char ch : s) {
            if (ch == '#') {
                if (!res.empty())
                    res += res;
            } else if (ch == '%') {
                reverse(res.begin(), res.end());
            } else if (ch == '*') {
                if (!res.empty())
                    res.pop_back();
            } else {
                res += ch;
            }
        }
        return res;
    }
};
