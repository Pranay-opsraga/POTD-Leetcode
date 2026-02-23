class Solution {
public:
    bool hasAllCodes(string s, int k) {
          int range = 1 << k;
          int n = s.size();

          if(n - k + 1 < range) return false;

          vector<bool>seen(range , false);
          int mask = range-1;
          int hash = 0;
          int cnt = 0;

          for( int i = 0 ; i < n ; i++){
              hash = ((hash << 1) & mask ) | (s[i] - '0');

              if( i >= k-1){
                  if(!seen[hash]){
                     seen[hash] = true;
                     cnt++;
                     if(cnt == range) return true;
                  }
              } 
          }
          return false;
    }
};
