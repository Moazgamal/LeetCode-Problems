class Solution {
public:
    long long calculateScore(string s) {
        long long ans = 0; 
        unordered_map<char, vector<int>>mp;
        for(int i = 0; i< s.size(); i++)
        {
            int idx = 25-(s[i]-'a');
            char c = idx+'a';
            if(mp.count(c) > 0 && mp[c].size()>0)
            {
                int j = mp[c][mp[c].size()-1];
                mp[c].pop_back();
                ans += (i-j);
            }
            else
            {
                mp[s[i]].push_back(i);
            }
        }return ans;
        
    }
};