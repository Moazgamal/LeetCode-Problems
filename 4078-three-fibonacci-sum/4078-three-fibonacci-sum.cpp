class Solution {
public:
    bool threeFibonacciSum(int n) {
    int i = 0;
    long long j = 1;
    int temp = j;
    long long curVal = 0;
    while(curVal <n)
    {
        j = i+j;
        curVal = j+i+temp;
        i = temp;
        if(curVal == n)
            return true;
        temp =j;
    }
       return false;
    }
};