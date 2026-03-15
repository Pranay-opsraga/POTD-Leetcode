class Fancy {
public:
    long long mod = 1e9 + 7;
    vector<long long> arr;
    long long add = 0;
    long long multiply = 1;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b) {
            if (b & 1) {
                res = (res * a) % mod;
            }
            a = (a * a) % mod;
            b >>= 1;
        }
        return res;
    }

    Fancy() {}

    void append(int val) {
        long long x = (val - add + mod) % mod;
        x = (x * power(multiply, mod - 2)) % mod;
        arr.push_back(x);
    }

    void addAll(int inc) { add = (add + inc) % mod; }

    void multAll(int m) {
        multiply = (multiply * m) % mod;
        add = (add * m) % mod;
    }

    int getIndex(int idx) {
        if (idx >= arr.size())
            return -1;

        return (arr[idx] * multiply + add) % mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
