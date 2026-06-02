class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int ans = INT_MAX;
        int n = landStartTime.size();
        int m =  waterStartTime.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                // land -> water
                int landfinish = landStartTime[i] + landDuration[i];

                ans = min((max(landfinish, waterStartTime[j]) +  waterDuration[j]) , ans);

                // water -> land
                int waterfinish = waterStartTime[j] + waterDuration[j];

                ans = min((max(waterfinish, landStartTime[i]) + landDuration[i]) , ans);
            }
        }
        return ans;
    }
};
