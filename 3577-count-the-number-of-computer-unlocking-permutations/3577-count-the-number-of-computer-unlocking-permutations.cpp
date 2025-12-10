class Solution {
public:
    int countPermutations(vector<int>& complexity) {
            static const int MOD = 1000000007;

        int n = complexity.size();
        for (int i = 1; i < n; ++i) 
        {
            if (complexity[0] >= complexity[i]) 
                return 0;
        }
        long long ans = 1;
        for (int i = 2; i < n; ++i) {
            ans = ans * i % MOD;
        }
        return (int)ans;
    }
};