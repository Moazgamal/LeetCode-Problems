class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int ans  = 0 ; 
        for(int i = 1; i<= n; i++)
        {
            int sum  = 0; 
            string s = to_string(i);
            for(int j = 0; j< s.size(); j++)
            {
                sum += (s[j]-'0');
            }
            mp[sum]++; ans = max(ans, mp[sum]);
        }
        int res = 0; 
        for(auto x: mp)
        {
            if(x.second == ans)
                res++;
        }return res;
    }
};