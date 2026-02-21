class Solution {
public:
    int countPrimeSetBits(int left, int right) {
          
          int max = 20;

          vector<bool>isPrime(max+1 , true);
          isPrime[0] = isPrime[1] = false;

          for(int i = 2 ; i*i <= max ; i++){
                if(isPrime[i]){
                    for(int j = i*i ; j <= max ; j+= i){
                         isPrime[j] = false;
                    }
                }
          }

          int ans = 0;
          for(int i = left ; i <= right; i++){
                int cnt = __builtin_popcount(i);
                if(isPrime[cnt]) ans++;
          }
          return ans;
    }
};
