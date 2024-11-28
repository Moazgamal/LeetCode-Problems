class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>>freq(nums.size()+1);
        unordered_map<int,int>mp;
        for(int i = 0; i< nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        for(auto x: mp)
        {
            freq[x.second].push_back(x.first);
        }
        vector<int> result;
        for(int i = freq.size()-1; i>=0; i--)
        {
            for(int j = 0; j< freq[i].size(); j++)
            {
                if(result.size()== k)
                    break;
                result.push_back(freq[i][j]);
            }
        }return result;
    }
};