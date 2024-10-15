class Solution {
public:
    long long minimumSteps(string s) {

        int sum = 0;
        long long ans = 0;
        for(int i = s.size()-1; i>=0; i--)
        {
            if(s[i] == '1')
            {
                if(sum>0)
                    ans+=(sum);
            }
            else
            {
                sum++;
            }
        }return ans;
        
    }
};