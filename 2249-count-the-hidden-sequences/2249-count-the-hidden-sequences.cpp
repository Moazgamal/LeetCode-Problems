class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        int mini = lower;
        int maxi = upper;

        for(int i = 0; i< differences.size(); i++)
        {
            mini += differences[i];
            maxi += differences[i];
            if(mini > upper || maxi < lower)
                return 0; 
            if(mini < lower)
                mini = lower;
            if(maxi > upper)
                maxi = upper;
        }
        return maxi-mini+1;



    }
};