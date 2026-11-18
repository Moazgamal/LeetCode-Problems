class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {
        
        int rSource = source[0];
        int cSource = source[1];
        int rTarget = target[0];
        int cTarget = target[1];
        int sum = rSource + cSource;
        int Diff = rTarget - cTarget;
        

        if((rSource-cSource) == (rTarget-cTarget) || (rSource+cSource) == (rTarget+cTarget))
            return 1;
        
        int rem = ((sum)+(Diff))%2;

        if(rem == 0)
        {
            int r = ((sum)+(Diff))/2;
            int c = sum-r;
            if(r >=1 && r<9 && c>=1 && c<9)
                return 2;
        }
        sum = rTarget + cTarget;
        Diff = rSource - cSource;
        rem = rem = ((sum)+(Diff))%2;
        if(rem == 0)
        {
            int r = ((sum)+(Diff))/2;
            int c = sum-r;
            if(r >=1 && r<9 && c>=1 && c<9)
                return 2;
        }
        return -1;
    }
};