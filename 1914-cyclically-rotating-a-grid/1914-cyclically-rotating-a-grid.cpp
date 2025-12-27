class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        int top = 0, left = 0;
        int bottom = m - 1, right = n - 1;

        while (top < bottom && left < right) {
            vector<int> v;

            // top row
            for (int j = left; j <= right; j++)
                v.push_back(grid[top][j]);

            // right column
            for (int i = top + 1; i <= bottom; i++)
                v.push_back(grid[i][right]);

            // bottom row
            for (int j = right - 1; j >= left; j--)
                v.push_back(grid[bottom][j]);

            // left column
            for (int i = bottom - 1; i > top; i--)
                v.push_back(grid[i][left]);

            int len = v.size();
            int rot = k % len;

            // Counter-Clockwise
            rotate(v.begin(), v.begin() + rot, v.end());

            int idx = 0;

            // write back
            for (int j = left; j <= right; j++)
                grid[top][j] = v[idx++];

            for (int i = top + 1; i <= bottom; i++)
                grid[i][right] = v[idx++];

            for (int j = right - 1; j >= left; j--)
                grid[bottom][j] = v[idx++];

            for (int i = bottom - 1; i > top; i--)
                grid[i][left] = v[idx++];

            top++; left++;
            bottom--; right--;
        }

        return grid;
    }
};
