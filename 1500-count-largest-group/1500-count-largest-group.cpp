class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int,int>mp;
        int ans  = 0 ; 
        for(int i = 1; i<= n; i++)
        {
            int sum  = 0; 
            int j = i;
            while(j > 0)
            {
                sum += (j%10);
                j /= 10;
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