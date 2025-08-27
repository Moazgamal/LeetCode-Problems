class Solution {
    const int MOD = 1e9 + 7;

    long long factorial_mod(int n) { // kept for your style (not used now)
        long long res = 1;
        for (int i = 2; i <= n; i++) res = (res * i) % MOD;
        return res % MOD;
    }

    // Same signature to preserve your style; we only use n, k, used, dp.
    long long fn(int lastG, std::unordered_set<int>& st, int &n, int k, int used,
                 std::vector<std::vector<long long>>& dp, std::unordered_set<int>& st2, int &_k)
    {
        int rem = n - used;                 // how many sticks remain to place

        if (k < 0 || k > rem) return 0;     // impossible states

        auto &ret = dp[rem][k];             // memo by (rem, k)
        if (ret != -1) return ret;

        if (rem == 0) return ret = (k == 0); // no sticks left: valid iff need 0 visibles
        if (k == 0)  return ret = 0;         // sticks left but need 0 visibles → impossible

        // Option 1: tallest is visible (goes in front)
        long long take_visible = fn(lastG, st, n, k - 1, used + 1, dp, st2, _k);

        // Option 2: tallest is hidden (inserted after someone taller) → (rem-1) choices
        long long take_hidden  = fn(lastG, st, n, k,     used + 1, dp, st2, _k);
        long long ways = (take_visible + (long long)(rem - 1) * take_hidden) % MOD;

        return ret = ways;
    }
public:
    int rearrangeSticks(int n, int k) {
        // Keep your sets to preserve the look-and-feel, though we don't need them now.
        std::unordered_set<int> st, st2;
        for (int i = 1; i <= n; i++) { st.insert(i); st2.insert(i); }

        // dp indexed by (rem = 0..n) × (k = 0..k)
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(k + 1, -1));

        return (int)fn(0, st, n, k, 0, dp, st2, k);
    }
};
