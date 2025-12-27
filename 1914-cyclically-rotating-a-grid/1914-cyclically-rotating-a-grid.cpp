class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {

        int rows = grid.size();
        int cols = grid[0].size();

        int cnt1 = rows, cnt2 = cols;
        int r = 0, c = 0;

        while (cnt1 > 1 && cnt2 > 1) {
            int y = 2 * (cnt1 + cnt2) - 4;
            int _k = k % y;

            int curRow = r;
            int curCol = c;
            int maxr = curRow + cnt1;
            int maxc = curCol + cnt2;

            vector<int> v;

            // ===== READ (Clockwise) =====

            // top row
            for (int col = curCol; col < maxc; col++)
                v.push_back(grid[curRow][col]);

            // right column
            for (int row = curRow + 1; row < maxr; row++)
                v.push_back(grid[row][maxc - 1]);

            // bottom row
            for (int col = maxc - 2; col >= curCol; col--)
                v.push_back(grid[maxr - 1][col]);

            // left column
            for (int row = maxr - 2; row > curRow; row--)
                v.push_back(grid[row][curCol]);

            // ===== ROTATE (Counter-Clockwise) =====
            rotate(v.begin(), v.begin() + _k, v.end());

            int i = 0;

            // ===== WRITE BACK (Clockwise) =====

            // top row
            for (int col = curCol; col < maxc; col++)
                grid[curRow][col] = v[i++];

            // right column
            for (int row = curRow + 1; row < maxr; row++)
                grid[row][maxc - 1] = v[i++];

            // bottom row
            for (int col = maxc - 2; col >= curCol; col--)
                grid[maxr - 1][col] = v[i++];

            // left column
            for (int row = maxr - 2; row > curRow; row--)
                grid[row][curCol] = v[i++];

            r++; c++;
            cnt1 -= 2;
            cnt2 -= 2;
        }

        return grid;
    }
};
