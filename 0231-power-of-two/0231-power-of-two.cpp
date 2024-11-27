class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==0 || n<0)
            return false;
        double no1 = log2(n);
        return (long long)no1 == no1;
        
    }
};