class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int count0 = 0;
        vector<int> operations(n + 1, -1);
        queue<int> q;
        for (char& c : s) {
            if (c == '0')
                count0++;
        }
        q.push(count0);
        operations[count0] = 0;

        while (!q.empty()) {
            int z = q.front();
            q.pop();

            int minf = max(0, k - n + z);
            int maxf = min(k, z);

            for (int i = minf; i <= maxf; i++) {
                int newZ = z + k - 2 * i;

                if (operations[newZ] == -1) {
                    operations[newZ] = operations[z] + 1;
                    if (newZ == 0) return operations[newZ];

                    q.push(newZ);
                }
            }
        }
        return -1;
    }
};


// Optimal 

class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.size();
        int count0 = 0;
        vector<int> operations(n + 1, -1);
        queue<int> q;
        for (char& c : s) {
            if (c == '0')
                count0++;
        }

        if (count0 == 0) {
            return 0;
        }

        q.push(count0);
        operations[count0] = 0;

        set<int> evenset;
        set<int> oddset;

        for (int i = 0; i <= n; i++) {
            if (i & 1)
                oddset.insert(i);
            else
                evenset.insert(i);
        }

        if (count0 % 2 == 0) {
            evenset.erase(count0);
        } else {
            oddset.erase(count0);
        }

        while (!q.empty()) {
            int z = q.front();
            q.pop();

            int newZ_max = z + k - 2 * max(0, k - n + z);
            int newZ_min = z + k - 2 * min(k, z);

            set<int>& currset = (newZ_min & 1) ? oddset : evenset;

            auto it = currset.lower_bound(newZ_min);

            while (it != currset.end() && *it <= newZ_max) {
                int newZ = *it;

                if (operations[newZ] == -1) {
                    operations[newZ] = operations[z] + 1;
                    if (newZ == 0)
                        return operations[newZ];

                    q.push(newZ);
                }

                it = currset.erase(it);
            }
        }
        return -1;
    }
};
