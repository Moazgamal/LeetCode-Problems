class Solution {
public:
    long long numOfSubsequences(string s) {
        int acc =0;
        vector<int>v(s.size(),0);
        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] == 'L')
            {
                acc++;
            }
            v[i]= acc;
        }

        long long totalSum=0;
        long long totalT=0;
        long long totalC = 0; 
        long long Extra = 0; 
        long long ans = 0; 
        long long val = 0; 
        for(int i = (int)s.size()-1; i>=0; i--)
        {
            if(s[i] == 'T')
            {
                totalT++; 
            }
            else if(s[i] == 'C')
            {
                totalC++;
                totalSum += totalT;
            }
            else if(s[i] == 'L')
            {
                val += totalC;
                ans += totalSum;
                Extra = max(Extra, totalT*v[i]);
            }
        }
        Extra = max(Extra, totalSum);
        Extra= max(Extra, val);

        return ans + Extra;

        
    }
};