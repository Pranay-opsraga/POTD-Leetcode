class Solution {
public:
    bool can(int mountainH, vector<int>& workerTimes, long long T) {
        long long total = 0;

        for (long long t : workerTimes) {
            long double val = sqrt((long double)t * t + 8.0L * t * T);
            long long x = (-t + val) / (2LL * t);
            total += x;

            if (total >= mountainH)
                return true;
        }

        return false;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1;
        long long x = mountainHeight;
        long long high = *max_element(workerTimes.begin(), workerTimes.end());
        high = high * (x * (x + 1) / 2);
        long long ans = 0;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            if (can(x, workerTimes, mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
