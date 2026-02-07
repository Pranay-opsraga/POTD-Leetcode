class Solution {
public:
    int minimumDeletions(string s) {
        
         int n = s.size();
         int cntB = 0;
         int ans = 0;

         for(char ch : s){
              if(ch == 'b') cntB++;
              else {
                 ans = min(ans+1 , cntB );
              }
         }
         return ans;
    }

};
