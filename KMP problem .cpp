class Solution {
public:
    vector<int> flps(string& needle) {
        int m = needle.size();
        vector<int> lps(m, 0);
        int len = 0;
        int i = 1;

        while (i < m) {
            if (needle[i] == needle[len]) {
                len++;
                lps[i] = len;
                i++;
            } else {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }

        return lps;
    }
    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int m = needle.size();

        int i = 0;
        int j = 0;
        vector<int> lps = flps(needle);

        while (i < n) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
            }

            if (j == m) {
                return i - j;
            } else if (i < n && haystack[i] != needle[j]) {
                if (j > 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return -1;
    }
};
