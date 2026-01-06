class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = INT_MIN;
        long long accPos = 0; 
        int minAbsVal = INT_MAX;
        int negatives = 0; 
        long long absSum = 0; 
        for(int r = 0; r< matrix.size(); r++)
        {
            for(int c = 0; c< matrix[0].size(); c++)
            {
                if(matrix[r][c] > 0)
                {
                    accPos += matrix[r][c];
                }
                else if(matrix[r][c]<0)
                    negatives++;
                minAbsVal = min(minAbsVal, abs(matrix[r][c]));
                absSum += abs(matrix[r][c]);
            }
        }
        if(negatives %2 == 0)
        {
            return absSum;
        }
        return absSum - 2LL *minAbsVal;
    }
};