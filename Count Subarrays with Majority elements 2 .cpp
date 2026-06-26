 class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        using ll = long long;

        unordered_map<int, int> mpp;
        int cumsum = 0;
        mpp[0] = 1;
        ll validLeftPoints = 0;
        ll result = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == target) {
                validLeftPoints += mpp[cumsum];
                cumsum++;
            } else {
                cumsum -= 1;
                validLeftPoints -= mpp[cumsum];
            }
            mpp[cumsum] += 1;
            result += validLeftPoints;
        }

        return result;
    }
};
