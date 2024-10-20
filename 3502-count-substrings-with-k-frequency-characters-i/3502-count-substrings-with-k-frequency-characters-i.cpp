class Solution {
public:
    int numberOfSubstrings(string s, int k) {

        int j =0;
        unordered_map<char,int>mp;
        int ans = 0;
        for(int i = 0; i< s.size(); i++)
        {
            mp[s[i]]++;
            if(mp[s[i]] == k)
            {
                while(j<=i && mp[s[i]] == k)
                {
                    ans+=(s.size()-i);
                    mp[s[j]]--;
                    j++;
                }
            }
        }return ans;
        
    }
};