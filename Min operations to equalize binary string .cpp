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
