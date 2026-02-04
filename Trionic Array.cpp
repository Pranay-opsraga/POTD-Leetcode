class Solution {
public:
    bool isTrionic(vector<int>& nums) {

        int n = nums.size();

        if (n < 4)
            return false;

        int phase = 1;

        for (int i = 1; i < n; i++) {

            if (nums[i] == nums[i - 1])
                return false;
            if(nums[0] > nums[1]) return false; // if it is already decreasing 

            if (phase == 1) {
                if (nums[i - 1] > nums[i]) {
                    phase = 2;
                }
            }

            else if (phase == 2) {
                if (nums[i - 1] < nums[i]) {
                    phase = 3;
                }
            }

            else { // phase 3
                if (nums[i] < nums[i - 1]) {
                    return false; // cannot decrease again
                }
            }
        }
        return (phase == 3) ? true : false ;
    }
};
