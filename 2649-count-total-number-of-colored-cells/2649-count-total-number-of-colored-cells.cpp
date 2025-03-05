class Solution {
public:
    long long coloredCells(int n) {
        long long ans = 1;
        long long factor = 4;
        for(int i =2; i<=n; i++)
        {
            ans += factor;
            factor += 4;
        }return ans;
    }
};