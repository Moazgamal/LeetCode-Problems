class Solution {
public:
    long long minEnd(int n, int x) {
        if(n==1)
            return x;
        long long num = x;
        n--;
        while(n>0)
        {
           num = ((num+1)|x);
           n--;
        }return num;
        
    }
};