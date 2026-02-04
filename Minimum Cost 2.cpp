class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {

        multiset<int> small, big;
        int n = nums.size();

        long long sum = 0;

        for (int i = 1; i <= dist + 1; i++) { // first window

            int x = nums[i];

            if (small.size() < k - 1) {
                small.insert(x);
                sum += x;
            } else {
                auto it = prev(small.end());
                if (x < *it) {
                    sum -= *it;
                    big.insert(*it);
                    small.erase(it);

                    small.insert(x);
                    sum += x;
                } else {
                    big.insert(x);
                }
            }
        }

        // rest of the window
        int point = 1;
        long long ans = nums[0] + sum;

        for (int i = dist + 2; i < n; i++) {

            // remove outgoing
            int out = nums[point];
            point++;

            if (!small.empty() && out <= *prev(small.end())) {
                auto it = small.find(out);
                small.erase(it);
                sum -= out;

                if (!big.empty()) {
                    int val = *big.begin();
                    big.erase(big.begin());
                    small.insert(val);
                    sum += val;
                }
            } else {
                big.erase(big.find(out));
            }

            // Inserting elements

            int in = nums[i];

            if (small.size() < k - 1) {
                small.insert(in);
                sum += in;
            } else {
                auto it = prev(small.end());
                if (in < *it) {
                    sum -= *it;
                    big.insert(*it);
                    small.erase(it);

                    small.insert(in);
                    sum += in;
                } else {
                    big.insert(in);
                }
            }
            ans = min(ans, nums[0] + sum);
        }

        return ans;
    }
};
