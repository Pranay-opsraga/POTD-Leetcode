class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
             
             int n = nums.size();
             vector<int>arr;

             for(int i = 0 ; i < n ; i++){
                   

                  int val = (i + nums[i]) % n ;
                  if(val < 0) val = (val + n ) % n;
                   arr.push_back(nums[val]); 
             }
           return arr;  
    }
};
