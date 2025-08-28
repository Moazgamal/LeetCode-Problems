class Solution {
    bool isvalid(int r, int c, int rows, int cols) {
        return !(r < 0 || c < 0 || r >= rows || c >= cols);
    }
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> g1(rows, vector<int>(cols, 0)); // ↘
        vector<vector<int>> g2(rows, vector<int>(cols, 0)); // ↖
        vector<vector<int>> g3(rows, vector<int>(cols, 0)); // ↙
        vector<vector<int>> g4(rows, vector<int>(cols, 0)); // ↗

        auto nextVal = [&](int v)->int {
            if (v == 1) return 2;
            return (v == 2 ? 0 : 2);
        };

        // g1: ↘ (dr=+1, dc=+1), نمسح من آخر الصفوف والاعمدة
        for (int r = rows-1; r >= 0; --r) {
            for (int c = cols-1; c >= 0; --c) {
                int val = grid[r][c];
                int expect = nextVal(val);
                int nr = r+1, nc = c+1;
                if (isvalid(nr,nc,rows,cols) && grid[nr][nc] == expect) 
                    g1[r][c] = 1 + g1[nr][nc];
                else 
                    g1[r][c] = 1;
            }
        }

        // g2: ↖ (dr=-1, dc=-1), نمسح من بداية الصفوف والاعمدة
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                int val = grid[r][c];
                int expect = nextVal(val);
                int nr = r-1, nc = c-1;
                if (isvalid(nr,nc,rows,cols) && grid[nr][nc] == expect)
                    g2[r][c] = 1 + g2[nr][nc];
                else 
                    g2[r][c] = 1;
            }
        }

        // g3: ↙ (dr=+1, dc=-1), نمسح من آخر الصفوف وبداية الاعمدة
        for (int r = rows-1; r >= 0; --r) {
            for (int c = 0; c < cols; ++c) {
                int val = grid[r][c];
                int expect = nextVal(val);
                int nr = r+1, nc = c-1;
                if (isvalid(nr,nc,rows,cols) && grid[nr][nc] == expect)
                    g3[r][c] = 1 + g3[nr][nc];
                else 
                    g3[r][c] = 1;
            }
        }

        // g4: ↗ (dr=-1, dc=+1), نمسح من بداية الصفوف وآخر الاعمدة
        for (int r = 0; r < rows; ++r) {
            for (int c = cols-1; c >= 0; --c) {
                int val = grid[r][c];
                int expect = nextVal(val);
                int nr = r-1, nc = c+1;
                if (isvalid(nr,nc,rows,cols) && grid[nr][nc] == expect)
                    g4[r][c] = 1 + g4[nr][nc];
                else 
                    g4[r][c] = 1;
            }
        }

        int ans = 0;

        // دلوقتي نجرّب كل خلية =1 كنقطة بداية
        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] != 1) continue;
                ans = max(ans, 1);

                // بدون لفة
                ans = max(ans, g1[r][c]);
                ans = max(ans, g2[r][c]);
                ans = max(ans, g3[r][c]);
                ans = max(ans, g4[r][c]);

                // بلفة (نفس فكرتك الأصلية: نمشي خطوة خطوة ونضم الطرف الثاني)
                // ↘ + ↙
                {
                    int h = 1, row=r+1, col=c+1, x=2;
                    while(isvalid(row,col,rows,cols) && grid[row][col]==x) {
                        ans = max(ans, h + g3[row][col]);
                        h++; row++; col++; x = (x==2?0:2);
                    }
                }
                // ↙ + ↖
                {
                    int h = 1, row=r+1, col=c-1, x=2;
                    while(isvalid(row,col,rows,cols) && grid[row][col]==x) {
                        ans = max(ans, h + g2[row][col]);
                        h++; row++; col--; x = (x==2?0:2);
                    }
                }
                // ↖ + ↗
                {
                    int h = 1, row=r-1, col=c-1, x=2;
                    while(isvalid(row,col,rows,cols) && grid[row][col]==x) {
                        ans = max(ans, h + g4[row][col]);
                        h++; row--; col--; x = (x==2?0:2);
                    }
                }
                // ↗ + ↘
                {
                    int h = 1, row=r-1, col=c+1, x=2;
                    while(isvalid(row,col,rows,cols) && grid[row][col]==x) {
                        ans = max(ans, h + g1[row][col]);
                        h++; row--; col++; x = (x==2?0:2);
                    }
                }
            }
        }
        return ans;
    }
};
