class Solution {
    bool isvalid(int r, int c, vector<vector<int>> &grid)
{
	if(r< 0 || c< 0 || r>= grid.size() || c>= grid[0].size())
		return false;
	return true;
}
int dfs(int r, int c, vector<vector<int>>&dp, vector<vector<int>> & grid)
{

	auto &ret = dp[r][c];
	if(ret != -1)
		return ret;
	if(grid[r][c]==0)
		return ret =0;
	if(!isvalid(r,c+1,grid) || !isvalid(r+1,c,grid) || !isvalid(r+1,c+1,grid))
		return ret = 1;
	int c1 = dfs(r,c+1,dp,grid);
	int c2 = dfs(r+1,c,dp,grid);
	int c3 = dfs(r+1, c+1, dp, grid);
	ret = 1+min(c1, min(c2,c3));
    return ret ;
}
public:
    int countSquares(vector<vector<int>>& matrix) {

        int ans =0;
	vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size(),-1));
	for(int r = 0; r< matrix.size(); r++)
	{
		for(int c = 0; c< matrix[0].size(); c++)
		{
			if(matrix[r][c] == 1)
			{
				if(dp[r][c] != -1)
					ans+=dp[r][c];
                else
                    ans+=(dfs(r,c,dp,matrix));
                
			}
		}
	}
	return ans;

        
        
    }
};