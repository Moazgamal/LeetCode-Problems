class Solution {
    int backtracking(vector<vector<int>>&mat, int curRow, int curTarget,
    vector<int>&sums, vector<vector<int>>&Dp)
    {
        if(curRow==mat.size())
            return curTarget;
        auto &ret = Dp[curRow][curTarget];
        if(ret != -1)
            return ret; 
        ret = INT_MAX;
        for(int c = 0; c < mat[curRow].size(); c++)
        {
            if(curTarget-mat[curRow][c]>0)
            {
                ret = 
                min
                (
                    ret, 
                backtracking(mat, curRow+1, curTarget-mat[curRow][c],sums, Dp)
                );
            }
            else
            {
                if(curRow == mat.size()-1)
                    ret = min(ret, (mat[curRow][c])-curTarget);
                else
                    ret = min(ret, (mat[curRow][c]+sums[curRow+1])-curTarget);
                return ret; 
            }
        }
        return ret; 
    }
public:
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {

        for(int r = 0; r< mat.size(); r++)
            sort(mat[r].begin(), mat[r].end());

        vector<int>sums(mat.size(),0);
        int maxiSum = mat[mat.size()-1][mat[0].size()-1]; 
        sums[mat.size()-1] = mat[mat.size()-1][0];

        for(int r = mat.size()-2; r >= 0; r--)
        {
            sums[r] = sums[r+1]+mat[r][0];
            maxiSum += mat[r][mat[0].size()-1];
        }
        int miniSum = sums[0];

        if(miniSum >= target)
            return miniSum-target;

        if(maxiSum <= target)
            return target-maxiSum;
        
        vector<vector<int>>Dp(mat.size(), vector<int>(target+1, -1));
        return backtracking(mat, 0, target, sums, Dp);
    }
};