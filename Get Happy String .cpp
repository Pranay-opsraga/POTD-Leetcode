class Solution {
public:
    void solve(int n, int k, int& cnt, string& curr, string& ans) {
        if (curr.size() == n) { // Base Case
            cnt++;
            if (cnt == k) {
                ans = curr;
            }
            return;
        }

        for (char ch = 'a'; ch <= 'c'; ch++) {
            if (!curr.empty() && curr.back() == ch)
                continue;

            curr.push_back(ch);
            solve(n, k, cnt, curr, ans);
            curr.pop_back();

            if (!ans.empty())
                return;
        }
    }
    string getHappyString(int n, int k) {
        string curr = "";
        string ans = "";
        int cnt = 0;
        solve(n, k, cnt, curr, ans);
        return ans;
    }
};
