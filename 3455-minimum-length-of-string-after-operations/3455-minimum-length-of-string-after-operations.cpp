class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char,int>mp;
        for(int i =0; i< s.size(); i++)
        {
            mp[s[i]]++;
        }
        int ans = 0; 
        for(auto x: mp)
        {
            if(x.second %2 ==0)
            {
                ans+=2;
            }
            else
            {
                ans += 1;
            }
        }return ans;
    }
};