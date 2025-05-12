class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Precompute row‐ and column‐sums & total
        vector<long long> rows(m), cols(n);
        long long tot = 0;
        unordered_map<long long,int> mp;
        for (int i = 0; i < m; i++) {
            long long s = 0;
            for (int j = 0; j < n; j++) {
                s += grid[i][j];
                mp[grid[i][j]]++;
            }
            rows[i] = s;
            tot += s;
        }
        for (int j = 0; j < n; j++) {
            long long s = 0;
            for (int i = 0; i < m; i++) {
                s += grid[i][j];
            }
            cols[j] = s;
        }

        // Horizontal cuts
        long long sum1 = 0;
        for (int i = 0; i < m - 1; i++) 
        {
            sum1 += rows[i];
            long long other = tot - sum1;
            if (sum1 == other) 
                return true;

            long long diff = llabs(sum1 - other);
            if (mp[diff] == 0) 
                continue;

        

            if (sum1 > other) 
            {
                // Try removing diff from top [rows 0..i] × [cols 0..n-1]
                int H = i + 1, W = n;
                // 2D guard
                if (H > 1 && W > 1) return true;
                // otherwise only ends
                if (H == 1) {
                    // single row = row 0 ..0, so row index = 0
                    if (grid[0][0] == diff || grid[0][W-1] == diff)
                        return true;
                } else { 
                    // W == 1, single column
                    if (grid[0][0] == diff || grid[H-1][0] == diff)
                        return true;
                }
            } else {
                // Removing diff from bottom [rows i+1..m-1] × [cols 0..n-1]
                int H = m - (i + 1), W = n;
                if (H > 1 && W > 1) return true;
                int row = i + 1;
                if (H == 1) {
                    // single row at index row
                    if (grid[row][0] == diff || grid[row][W-1] == diff)
                        return true;
                } else {
                    // single col
                    if (grid[0][0] == diff || grid[H-1][0] == diff)
                        return true;
                }
            }
        }

        // Vertical cuts
        sum1 = 0;
        for (int j = 0; j < n - 1; j++) {
            sum1 += cols[j];
            long long other = tot - sum1;
            if (sum1 == other)
                return true;

            long long diff = llabs(sum1 - other);
            if (mp[diff] == 0)
                continue;

            if (sum1 > other) {
                // Remove from left [rows 0..m-1] × [cols 0..j]
                int H = m, W = j + 1;
                if (H > 1 && W > 1) return true;
                if (H == 1) {
                    // single row = row 0
                    if (grid[0][0] == diff || grid[0][W-1] == diff)
                        return true;
                } else {
                    // single col at c = j
                    if (grid[0][j] == diff || grid[H-1][j] == diff)
                        return true;
                }
            } else {
                // Remove from right [rows 0..m-1] × [cols j+1..n-1]
                int H = m, W = n - (j + 1);
                if (H > 1 && W > 1) return true;
                int c = j + 1;
                if (H == 1) {
                    if (grid[0][c] == diff || grid[0][n-1] == diff)
                        return true;
                } else {
                    if (grid[0][c] == diff || grid[H-1][c] == diff)
                        return true;
                }
            }
        }

        return false;
    }
};
