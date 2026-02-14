class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int rowMin = INT_MAX; int rowMax = INT_MIN;
        int colMin = INT_MAX; int colMax = INT_MIN;   
        for(int r = 0; r< grid.size(); r++)
        {
            for(int c = 0; c< grid[0].size(); c++)
            {
                if(grid[r][c] == 1)
                {
                    rowMin = min(rowMin, r); colMin = min(c, colMin);
                    rowMax = max(rowMax, r); colMax = max(c, colMax);
                }
            }
        }
        
        vector<vector<pair<int,int>>>v(grid.size(),
         vector<pair<int,int>>(grid[0].size()));
        for(int r = rowMin; r <= rowMax; r++)
        {
            int miniCol = INT_MAX; int maxiCol = INT_MIN;
            for(int c = colMin; c<= colMax; c++)
            {
                if(grid[r][c] == 1)
                {
                    miniCol = min(miniCol, c);
                    maxiCol = max(maxiCol, c);
                }
                v[r][c] = {miniCol, maxiCol};
            }
        }

        vector<vector<pair<int,int>>>v2(grid.size(),
         vector<pair<int,int>>(grid[0].size()));
        for(int c = colMin; c<= colMax; c++)
        {
            int miniRow = INT_MAX; int maxiRow = INT_MIN; 
            for(int r = rowMin; r <= rowMax; r++)
            {
                if(grid[r][c] == 1)
                {
                    miniRow = min(miniRow, r);
                    maxiRow = max(maxiRow, r);
                }
                v2[r][c] = {miniRow, maxiRow};
            }
        }
        vector<vector<int>>mp1(grid.size(),vector<int>(grid.size()));
        for(int r = rowMin; r<= rowMax; r++)
        {
            int minR = INT_MAX; ; int maxR = INT_MIN;
            int accMini = INT_MAX; int accMaxi = INT_MIN;
            for(int rr = r; rr<= rowMax; rr++)
            {
                accMini = min(accMini, v[rr][colMax].first);
                accMaxi = max(accMaxi, v[rr][colMax].second);
                if(accMini == INT_MAX)
                    mp1[r][rr] = 0; 
                else
                {
                    minR = min(minR, rr); maxR = max(maxR, rr);
                    mp1[r][rr] = (maxR-minR+1)*(accMaxi-accMini+1);
                }
            }
        }
        vector<vector<int>>mp2(grid[0].size(),vector<int>(grid[0].size()));
        for(int c = colMin; c<= colMax; c++)
        {
            int minC = INT_MAX; ; int maxC = INT_MIN;
            int accMini = INT_MAX; int accMaxi = INT_MIN;
            for(int cc = c; cc<= colMax; cc++)
            {
                accMini = min(accMini, v2[rowMax][cc].first);
                accMaxi = max(accMaxi, v2[rowMax][cc].second);
                if(accMini == INT_MAX)
                    mp2[c][cc] = 0;
                else
                {
                    minC = min(minC, cc); maxC = max(maxC, cc);
                    mp2[c][cc] = (maxC-minC+1)*(accMaxi-accMini+1);
                }
            }
        }
        // top left
        vector<vector<pair<pair<int,int>, pair<int,int>>>> topLeft
        (grid.size(), vector<pair<pair<int,int>,pair<int,int>>>(grid[0].size()));
        vector<vector<int>>topLeftArea(grid.size(), vector<int>(grid[0].size(),0));
        for(int r = rowMin; r<= rowMax; r++)
        {
            for(int c = colMin; c<= colMax; c++)
            {
                pair<pair<int,int>,pair<int,int>> prevRow = {{INT_MAX,INT_MIN}, {INT_MAX,INT_MIN}};
                pair<pair<int,int>,pair<int,int>> prevCol = {{INT_MAX,INT_MIN}, {INT_MAX,INT_MIN}};
                if(r != rowMin)
                    prevRow = topLeft[r-1][c];
                if(c!= colMin)
                    prevCol = topLeft[r][c-1];
                if(grid[r][c] == 1)
                {
                    topLeft[r][c].first.first = min(r,
                    min(prevRow.first.first, prevCol.first.first)
                    );

                    topLeft[r][c].first.second = max(r,
                    max(prevRow.first.second, prevCol.first.second)
                    );

                    topLeft[r][c].second.first = min(c,
                    min(prevRow.second.first, prevCol.second.first)
                    );

                    topLeft[r][c].second.second = max(c,
                    max(prevRow.second.second, prevCol.second.second)
                    );
                }
                else
                {
                    topLeft[r][c].first.first = min(
                    prevRow.first.first, prevCol.first.first
                    );

                    topLeft[r][c].first.second = max(
                    prevRow.first.second, prevCol.first.second
                    );

                    topLeft[r][c].second.first = min(
                    prevRow.second.first, prevCol.second.first
                    );

                    topLeft[r][c].second.second = max(
                    prevRow.second.second, prevCol.second.second
                    );
                }
                if(topLeft[r][c].first.first == INT_MAX)
                    topLeftArea[r][c] = 0;
                else
                    topLeftArea[r][c] = 
                    (topLeft[r][c].first.second-topLeft[r][c].first.first+1)*
                    (topLeft[r][c].second.second-topLeft[r][c].second.first+1);
            }
        }
        // top right
        vector<vector<pair<pair<int,int>, pair<int,int>>>> topRight
        (grid.size(), vector<pair<pair<int,int>,pair<int,int>>>(grid[0].size()));
        vector<vector<int>>topRightArea(grid.size(), vector<int>(grid[0].size(),0));
        for(int r = rowMin; r<= rowMax; r++)
        {
            for(int c = colMax; c>= colMin; c--)
            {
                pair<pair<int,int>,pair<int,int>> prevRow = {{INT_MAX,INT_MIN}, {INT_MAX,INT_MIN}};
                pair<pair<int,int>,pair<int,int>> prevCol = {{INT_MAX,INT_MIN}, {INT_MAX,INT_MIN}};
                if(r != rowMin)
                    prevRow = topRight[r-1][c];
                if(c!= colMax)
                    prevCol = topRight[r][c+1];
                if(grid[r][c] == 1)
                {
                    topRight[r][c].first.first = min(r,
                    min(prevRow.first.first, prevCol.first.first)
                    );

                    topRight[r][c].first.second = max(r,
                    max(prevRow.first.second, prevCol.first.second)
                    );

                    topRight[r][c].second.first = min(c,
                    min(prevRow.second.first, prevCol.second.first)
                    );

                    topRight[r][c].second.second = max(c,
                    max(prevRow.second.second, prevCol.second.second)
                    );
                }
                else
                {
                    topRight[r][c].first.first = min(
                    prevRow.first.first, prevCol.first.first
                    );

                    topRight[r][c].first.second = max(
                    prevRow.first.second, prevCol.first.second
                    );

                    topRight[r][c].second.first = min(
                    prevRow.second.first, prevCol.second.first
                    );

                    topRight[r][c].second.second = max(
                    prevRow.second.second, prevCol.second.second
                    );
                }
                if(topRight[r][c].first.first == INT_MAX)
                    topRightArea[r][c] = 0;
                else
                    topRightArea[r][c] = 
                    (topRight[r][c].first.second-topRight[r][c].first.first+1)*
                    (topRight[r][c].second.second-topRight[r][c].second.first+1);
            }
        }

        // bottom left
        vector<vector<pair<pair<int,int>, pair<int,int>>>> bottomLeft
        (grid.size(), vector<pair<pair<int,int>,pair<int,int>>>(grid[0].size()));
        vector<vector<int>>bottomLeftArea(grid.size(), vector<int>(grid[0].size(),0));
        for(int r = rowMax; r>= rowMin; r--)
        {
            for(int c = colMin; c<= colMax; c++)
            {
                pair<pair<int,int>,pair<int,int>> prevRow = {{INT_MAX,INT_MIN}, {INT_MAX,INT_MIN}};
                pair<pair<int,int>,pair<int,int>> prevCol = {{INT_MAX,INT_MIN}, {INT_MAX,INT_MIN}};
                if(r != rowMax)
                    prevRow = bottomLeft[r+1][c];
                if(c!= colMin)
                    prevCol = bottomLeft[r][c-1];
                if(grid[r][c] == 1)
                {
                    bottomLeft[r][c].first.first = min(r,
                    min(prevRow.first.first, prevCol.first.first)
                    );

                    bottomLeft[r][c].first.second = max(r,
                    max(prevRow.first.second, prevCol.first.second)
                    );

                    bottomLeft[r][c].second.first = min(c,
                    min(prevRow.second.first, prevCol.second.first)
                    );

                    bottomLeft[r][c].second.second = max(c,
                    max(prevRow.second.second, prevCol.second.second)
                    );
                }
                else
                {
                    bottomLeft[r][c].first.first = min(
                    prevRow.first.first, prevCol.first.first
                    );

                    bottomLeft[r][c].first.second = max(
                    prevRow.first.second, prevCol.first.second
                    );

                    bottomLeft[r][c].second.first = min(
                    prevRow.second.first, prevCol.second.first
                    );

                    bottomLeft[r][c].second.second = max(
                    prevRow.second.second, prevCol.second.second
                    );
                }
                if(bottomLeft[r][c].first.first == INT_MAX)
                    bottomLeftArea[r][c] = 0;
                else
                    bottomLeftArea[r][c] = 
                    (bottomLeft[r][c].first.second-bottomLeft[r][c].first.first+1)*
                    (bottomLeft[r][c].second.second-bottomLeft[r][c].second.first+1);
            }
        }

        // bottom right
        vector<vector<pair<pair<int,int>, pair<int,int>>>> bottomRight
        (grid.size(), vector<pair<pair<int,int>,pair<int,int>>>(grid[0].size()));
        vector<vector<int>>bottomRightArea(grid.size(), vector<int>(grid[0].size(),0));
        for(int r = rowMax; r>= rowMin; r--)
        {
            for(int c = colMax; c>= colMin; c--)
            {
                pair<pair<int,int>,pair<int,int>> prevRow = {{INT_MAX,INT_MIN}, {INT_MAX,INT_MIN}};
                pair<pair<int,int>,pair<int,int>> prevCol = {{INT_MAX,INT_MIN}, {INT_MAX,INT_MIN}};
                if(r != rowMax)
                    prevRow = bottomRight[r+1][c];
                if(c!= colMax)
                    prevCol = bottomRight[r][c+1];
                if(grid[r][c] == 1)
                {
                    bottomRight[r][c].first.first = min(r,
                    min(prevRow.first.first, prevCol.first.first)
                    );

                    bottomRight[r][c].first.second = max(r,
                    max(prevRow.first.second, prevCol.first.second)
                    );

                    bottomRight[r][c].second.first = min(c,
                    min(prevRow.second.first, prevCol.second.first)
                    );

                    bottomRight[r][c].second.second = max(c,
                    max(prevRow.second.second, prevCol.second.second)
                    );
                }
                else
                {
                    bottomRight[r][c].first.first = min(
                    prevRow.first.first, prevCol.first.first
                    );

                    bottomRight[r][c].first.second = max(
                    prevRow.first.second, prevCol.first.second
                    );

                    bottomRight[r][c].second.first = min(
                    prevRow.second.first, prevCol.second.first
                    );

                    bottomRight[r][c].second.second = max(
                    prevRow.second.second, prevCol.second.second
                    );
                }
                if(bottomRight[r][c].first.first == INT_MAX)
                    bottomRightArea[r][c] = 0;
                else
                    bottomRightArea[r][c] = 
                    (bottomRight[r][c].first.second-bottomRight[r][c].first.first+1)*
                    (bottomRight[r][c].second.second-bottomRight[r][c].second.first+1);
            }
        }
        


        // *********************************************
        for(int r = rowMax; r >= rowMin+2; r--)
        {
            int area1 = mp1[r][rowMax];
            for(int rr = r-1; rr>= rowMin+1; rr--)
            {
                int area2 = mp1[rr][r-1];
                int area3 = mp1[rowMin][rr-1];
                if(area1 == 0 && (area2 == 1 && area3 == 1))
                    area1 = 1;
                else if(area2 == 0 && (area1 == 1 && area3 == 1))
                    area2 = 1; 
                else if(area3 == 0 && (area1 == 1 && area2 == 1))
                    area3 = 1; 
                else if(area1 == 0 && area2 == 0)
                {
                    if(area3 == 1)
                    {
                        area1 = 1; area2 = 1; 
                    }
                    else if(area3 == 2)
                        area1 = 1; 
                }
                else if(area1 == 0 && area3 == 0)
                {
                    if(area2 == 1)
                    {
                        area1 = 1; area3 = 1; 
                    }
                    else if(area2 == 2)
                        area1 = 1; 
                }
                else if(area2 == 0 & area3 == 0)
                {
                    if(area1 == 1)
                    {
                        area2 = 1; area3 = 1; 
                    }
                    else if(area1 == 2)
                        area2 = 1; 
                }
                ans = min(ans, area1+area2+area3);
            }
        }
        // *****************************************
        for(int r = rowMax; r >= rowMin+1; r--)
        {
            int area1 = mp1[r][rowMax];
            for(int c = colMin; c<= colMax-1; c++)
            {
                int area2 = topLeftArea[r-1][c];
                int area3 = topRightArea[r-1][c+1];
                if(area1 == 0 && (area2 == 1 && area3 == 1))
                    area1 = 1;
                else if(area2 == 0 && (area1 == 1 && area3 == 1))
                    area2 = 1; 
                else if(area3 == 0 && (area1 == 1 && area2 == 1))
                    area3 = 1; 
                else if(area1 == 0 && area2 == 0)
                {
                    if(area3 == 1)
                    {
                        area1 = 1; area2 = 1; 
                    }
                    else if(area3 == 2)
                        area1 = 1; 
                }
                else if(area1 == 0 && area3 == 0)
                {
                    if(area2 == 1)
                    {
                        area1 = 1; area3 = 1; 
                    }
                    else if(area2 == 2)
                        area1 = 1; 
                }
                else if(area2 == 0 & area3 == 0)
                {
                    if(area1 == 1)
                    {
                        area2 = 1; area3 = 1; 
                    }
                    else if(area1 == 2)
                        area2 = 1; 
                }
                ans = min(ans, area1+area2+area3);
            }
        }
        // *******************************
        for(int r = rowMin; r <= rowMax-1; r++)
        {
            int area1 = mp1[rowMin][r];
            for(int c = colMin; c<= colMax-1; c++)
            {
                int area2 = bottomLeftArea[r+1][c];
                int area3 = bottomRightArea[r+1][c+1];
                if(area1 == 0 && (area2 == 1 && area3 == 1))
                    area1 = 1;
                else if(area2 == 0 && (area1 == 1 && area3 == 1))
                    area2 = 1; 
                else if(area3 == 0 && (area1 == 1 && area2 == 1))
                    area3 = 1; 
                else if(area1 == 0 && area2 == 0)
                {
                    if(area3 == 1)
                    {
                        area1 = 1; area2 = 1; 
                    }
                    else if(area3 == 2)
                        area1 = 1; 
                }
                else if(area1 == 0 && area3 == 0)
                {
                    if(area2 == 1)
                    {
                        area1 = 1; area3 = 1; 
                    }
                    else if(area2 == 2)
                        area1 = 1; 
                }
                else if(area2 == 0 & area3 == 0)
                {
                    if(area1 == 1)
                    {
                        area2 = 1; area3 = 1; 
                    }
                    else if(area1 == 2)
                        area2 = 1; 
                }
                ans = min(ans, area1+area2+area3);
            }
        }
        //*************************
        for(int c = colMin; c <= colMax-1; c++)
        {
            int area1 = topLeftArea[rowMax][c];
            for(int r = rowMax; r>=rowMin+1; r--)
            {
                int area2 = bottomRightArea[r][c+1];
                int area3 = topRightArea[r-1][c+1];
                if(area1 == 0 && (area2 == 1 && area3 == 1))
                    area1 = 1;
                else if(area2 == 0 && (area1 == 1 && area3 == 1))
                    area2 = 1; 
                else if(area3 == 0 && (area1 == 1 && area2 == 1))
                    area3 = 1; 
                else if(area1 == 0 && area2 == 0)
                {
                    if(area3 == 1)
                    {
                        area1 = 1; area2 = 1; 
                    }
                    else if(area3 == 2)
                        area1 = 1; 
                }
                else if(area1 == 0 && area3 == 0)
                {
                    if(area2 == 1)
                    {
                        area1 = 1; area3 = 1; 
                    }
                    else if(area2 == 2)
                        area1 = 1; 
                }
                else if(area2 == 0 & area3 == 0)
                {
                    if(area1 == 1)
                    {
                        area2 = 1; area3 = 1; 
                    }
                    else if(area1 == 2)
                        area2 = 1; 
                }
                cout<<area1<<" "<<area2<<" "<<area3<<"\n";
                ans = min(ans, area1+area2+area3);
            }
        }
        //*****************
        for(int c = colMax; c >= colMin+1; c--)
        {
            int area1 = topRightArea[rowMax][c];
            for(int r = rowMax; r>=rowMin+1; r--)
            {
                int area2 = bottomLeftArea[r][c-1];
                int area3 = topLeftArea[r-1][c-1];
                if(area1 == 0 && (area2 == 1 && area3 == 1))
                    area1 = 1;
                else if(area2 == 0 && (area1 == 1 && area3 == 1))
                    area2 = 1; 
                else if(area3 == 0 && (area1 == 1 && area2 == 1))
                    area3 = 1; 
                else if(area1 == 0 && area2 == 0)
                {
                    if(area3 == 1)
                    {
                        area1 = 1; area2 = 1; 
                    }
                    else if(area3 == 2)
                        area1 = 1; 
                }
                else if(area1 == 0 && area3 == 0)
                {
                    if(area2 == 1)
                    {
                        area1 = 1; area3 = 1; 
                    }
                    else if(area2 == 2)
                        area1 = 1; 
                }
                else if(area2 == 0 & area3 == 0)
                {
                    if(area1 == 1)
                    {
                        area2 = 1; area3 = 1; 
                    }
                    else if(area1 == 2)
                        area2 = 1; 
                }
                ans = min(ans, area1+area2+area3);
            }
        }
        //*************************
        for(int c = colMin; c <= colMax-2; c++)
        {
            int area1 = topLeftArea[rowMax][c];
            for(int cc = c+1; cc<=colMax-1; cc++)
            {
                int area2 = mp2[c+1][cc];
                int area3 = mp2[cc+1][colMax];
                if(area1 == 0 && (area2 == 1 && area3 == 1))
                    area1 = 1;
                else if(area2 == 0 && (area1 == 1 && area3 == 1))
                    area2 = 1; 
                else if(area3 == 0 && (area1 == 1 && area2 == 1))
                    area3 = 1; 
                else if(area1 == 0 && area2 == 0)
                {
                    if(area3 == 1)
                    {
                        area1 = 1; area2 = 1; 
                    }
                    else if(area3 == 2)
                        area1 = 1; 
                }
                else if(area1 == 0 && area3 == 0)
                {
                    if(area2 == 1)
                    {
                        area1 = 1; area3 = 1; 
                    }
                    else if(area2 == 2)
                        area1 = 1; 
                }
                else if(area2 == 0 & area3 == 0)
                {
                    if(area1 == 1)
                    {
                        area2 = 1; area3 = 1; 
                    }
                    else if(area1 == 2)
                        area2 = 1; 
                }
                ans = min(ans, area1+area2+area3);
            }
        }
        return ans; 
    }
};