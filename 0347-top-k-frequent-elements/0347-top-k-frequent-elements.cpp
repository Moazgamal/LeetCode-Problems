class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>v;
        unordered_map<int,int>mp;
        for(int i = 0; i< nums.size(); i++)
        {
            if(mp.count(nums[i])==0)
            {
                v.push_back({1, nums[i]});
                mp[nums[i]]=v.size()-1;
            }
            else
            {
                int idx = mp[nums[i]];
                v[idx].first++;
            }
        }
        sort(v.begin(), v.end());
        vector<int>ans;
        int j = v.size()-1;
        for(int i = 0; i< k; i++,j--)
            ans.push_back(v[j].second);
        return ans; 
    }
};