#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int MOD = 1e9 + 7;
    long long factorial_mod(int n) {
        long long res = 1;
        for (int i = 2; i <= n; i++) {
            res = (res * i) % MOD;
        }
        return res % MOD;
    }

    // kept your original signature and sets to preserve style
    long long fn(int lastG, int &n, int k, int used,
                 vector<vector<long long>>& dp, int &_k)
    {
        int rem = n - used; // remaining sticks

        if (k < 0 || k > rem) return 0;   // impossible
        if (rem == 0) return (k == 0) ? 1 : 0;

        // memo by (rem, k) instead of (k, used)
        auto &ret = dp[rem][k];
        if (ret != -1) return ret;

        // recurrence:
        // put current tallest visible -> f(rem-1, k-1)
        long long take_visible = fn(lastG, n, k - 1, used + 1, dp, _k);
        // put current tallest hidden -> (rem-1) * f(rem-1, k)
        long long take_hidden  = fn(lastG, n, k, used + 1, dp, _k);

        long long ways = (take_visible + ( (long long)(rem - 1) * take_hidden ) % MOD) % MOD;
        ret = ways;
        return ret;
    }

public:
    int rearrangeSticks(int n, int k) {

        // dp indexed by rem = 0..n and k = 0..k
        vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, -1));

        if (k > n) return 0;
        return (int)fn(0,  n, k, 0, dp, k);
    }
};
