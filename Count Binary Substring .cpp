class Solution {
public:
    int countBinarySubstrings(string s) {
           
            vector<int>arr;
            int n = s.size();

            int cnt = 1;

            for(int i = 1 ; i < n ; i++){
                  if(s[i] == s[i-1]) cnt++;
                  else {
                      arr.push_back(cnt);
                      cnt = 1;
                  }
            }

            arr.push_back(cnt);

            int ans = 0;

            for(int i = 1 ; i < arr.size() ; i++){
                 ans += min(arr[i], arr[i-1]);
            }
            return ans;
    }
};
