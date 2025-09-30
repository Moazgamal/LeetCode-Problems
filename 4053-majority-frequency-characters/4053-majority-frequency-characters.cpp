class Solution {
public:
    string majorityFrequencyGroup(string s) {
        string ans = "";
        unordered_map<char,int>mp1;
        map<int,vector<char>, greater<int>>mp2;
        for(int i = 0; i< s.size(); i++)
            mp1[s[i]]++;

        int maj = 0; 
        for(auto x: mp1)
        {
            mp2[x.second].push_back(x.first);
            maj = max(maj, (int)mp2[x.second].size());
        }
        for(auto x : mp2)
        {
            if(x.second.size() == maj)
            {
                for(auto y : x.second)
                    ans.push_back(y);

                return ans;
            }
        }
        return "";

        
    }
};