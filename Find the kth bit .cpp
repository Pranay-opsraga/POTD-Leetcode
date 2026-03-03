class Solution {
public:
    char solve(int n, int k) {
        if (n == 1)
            return '0';

        int len = (1 << n) - 1;
        int mid = (len + 1) / 2;

        if (k == mid)
            return '1';

        if (k < mid)
           return solve(n - 1, k);

         else {
              
            char bit =  solve(n-1 , len - k + 1);

            return (bit == '1') ? '0' : '1';
         }   
    }
    
    char findKthBit(int n, int k) { return solve(n, k); }
};
