class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int ans = 0; 
        vector<vector<int>>prefixRows(mat.size(), vector<int>(mat[0].size(),0));
        vector<vector<int>>prefixCols(mat.size(), vector<int>(mat[0].size(),0));
        for(int r = 0; r< mat.size(); r++)
        {
            int sum = 0; 
            for(int c=  0; c< mat[0].size(); c++)
            {
                sum+=mat[r][c];
                prefixRows[r][c] = sum;
            }
        }
        for(int c = 0; c< mat[0].size(); c++)
        {
            int sum = 0; 
            for(int r= 0; r< mat.size(); r++)
            {
                sum+= mat[r][c];
                prefixCols[r][c]= sum;
            }
        }

        for(int i  = 0; i< mat.size(); i++)
        {
            for(int j = 0; j< mat[0].size(); j++)
            {
                int r = i; int c = j; 
                int sum = 0;
                while(c<mat[0].size() && r< mat.size())
                {
                    int sumRow = 0; int sumCol = 0; 
                    if(j == 0)
                        sumRow= prefixRows[r][c];
                    else
                        sumRow = prefixRows[r][c]-prefixRows[r][j-1];
                    
                    if(i == 0)
                        sumCol = prefixCols[r][c];
                    else
                        sumCol = prefixCols[r][c]-prefixCols[i-1][c];
                    
                    sum += (sumRow+sumCol);
                    sum -= mat[r][c];
                    if(sum <=threshold )
                        ans = max(ans, (r-i)+1);
                    else
                        break;
                    r++; c++;
                }
            }
        }
        return ans; 
    }
};