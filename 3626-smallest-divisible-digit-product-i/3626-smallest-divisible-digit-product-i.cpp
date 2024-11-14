class Solution {
    bool fn(int val , int t)
    {
        int sum = 1;
        string s = to_string(val);
        for(int i = 0; i< s.size(); i++)
        {
            sum *= (s[i]-'0');
        } 
        if(sum %t ==0)
            return true;
        return false;
    }
public:
    int smallestNumber(int n, int t) {

        int start = n; int end = 100;
        for(int i = start; i<=end; i++)
        {
            if(fn(i,t))
                return i;
        }
        return 0; 
        
    }
};