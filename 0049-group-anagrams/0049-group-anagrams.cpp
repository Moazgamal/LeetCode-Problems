class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        vector<vector<string>> ans;
        int idx = 0; 
        unordered_map<string,vector<string>> mp;
        for(int i = 0; i< strs.size(); i++)
        {
            string cur = strs[i];
            sort(cur.begin(), cur.end());
            mp[cur].push_back(strs[i]);
        }
        for(auto it : mp)
        {
            ans.push_back(it.second);
        }
        return ans;
        
    }
};