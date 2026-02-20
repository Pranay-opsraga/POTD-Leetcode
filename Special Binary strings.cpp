class Solution {
public:
    string solve(string s) {
        vector<string> blocks;
        int cnt = 0, start = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1')
                cnt++;
            else
                cnt--;

            if (cnt == 0) {
                string inner = s.substr(start + 1, i - start - 1);
                inner = solve(inner);
                blocks.push_back("1" + inner + "0");
                start = i + 1;
            }
        }

        sort(blocks.rbegin(), blocks.rend());

        string ans = "";
        for (auto& b : blocks)
            ans += b;

        return ans;
    }
    string makeLargestSpecial(string s) { return solve(s); }
};
