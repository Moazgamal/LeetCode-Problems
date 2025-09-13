class Solution {
    long long fn(int start, long long final, vector<long long>&v, vector<long long>&ans)
    {
        if(final < 0)
            return LONG_MIN; 
        if(final %2 != 0)
            return LONG_MIN; 
        if(final == 0)
        {       
            ans = v;
            return 0; 
        }
        for(long long  i = start; i <= final; i += 2)
        {
            v.push_back(i);
            long long x = fn(i+2, final-i, v, ans);
            if(x == 0)
                return 0;
            v.pop_back();
        }
        return LONG_MIN;
    }
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum % 2 != 0)
            return {};
        vector<long long> v;
        vector<long long> ans;
        fn(2, finalSum, v, ans); 
        return ans;
        
        
    }
};