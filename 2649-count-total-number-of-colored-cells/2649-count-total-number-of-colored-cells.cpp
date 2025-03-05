class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        long long factor = 4;
        factor = n-1;
        factor = 4*(factor*(factor+1)/2);
        ans+=factor;
        return ans;
    }
};