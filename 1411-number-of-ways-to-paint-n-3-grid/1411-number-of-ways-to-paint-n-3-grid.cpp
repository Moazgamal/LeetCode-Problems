class Solution {
    int dp[5001][4][4][4] = {};
    int dfs(int n, int a0, int b0, int c0) {
        if (n == 0) return 1;
        if (dp[n][a0][b0][c0] != 0) return dp[n][a0][b0][c0];
        int ans = 0;
        vector<int> colors = {1, 2, 3}; // Red: 1, Yellow: 2, Green: 3
        for (int a : colors) {
            if (a == a0) continue; // Check if the same color with the below neighbor
            for (int b : colors) {
                if (b == b0 || b == a) continue; // Check if the same color with the below neighbor or the left neighbor
                for (int c : colors) {
                    if (c == c0 || c == b) continue; // Check if the same color with the below neighbor or the left neighbor
                    ans += dfs(n - 1, a, b, c);
                    ans %= 1000000007;
                }
            }
        }
        return dp[n][a0][b0][c0] = ans;
    }
public:
    int numOfWays(int n) {
        return dfs(n, 0, 0, 0);
        
    }
};