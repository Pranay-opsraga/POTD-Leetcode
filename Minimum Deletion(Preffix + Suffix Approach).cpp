class Solution {
public:
    int minimumDeletions(string s) {

        int n = s.size();

        vector<int> preffixB(n + 1, 0);
        vector<int> suffixA(n + 1, 0);

        int cntB = 0;
        for(int i = 0; i < n; i++){
            preffixB[i] = cntB;
            if(s[i] == 'b') cntB++;
        }
        preffixB[n] = cntB;

        int cntA = 0;
        for(int i = n - 1; i >= 0; i--){
            if(s[i] == 'a') cntA++;
            suffixA[i] = cntA;
        }
        suffixA[n] = 0;

        int ans = n;
        for(int i = 0; i <= n; i++){
            ans = min(ans, preffixB[i] + suffixA[i]);
        }

        return ans;
    }
};
