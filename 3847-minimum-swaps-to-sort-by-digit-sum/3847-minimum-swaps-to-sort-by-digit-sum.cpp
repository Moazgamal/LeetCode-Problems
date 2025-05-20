class Solution {
public:
    int minSwaps(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        for(int i = 0; i< nums.size(); i++)
        {
            
            mp[nums[i]]  = i;
        }
        vector<pair<int,int>> v;
        for(int  i = 0; i< nums.size(); i++)
        {
            string s = to_string(nums[i]);
            int sum = 0; 
            for(int j = 0; j< s.size(); j++)
            {
                sum += (s[j] -'0');
            }
            v.push_back({sum, nums[i]});
        }
        sort(v.begin(), v.end());
        int ans  =0; 
        for(int i = 0; i< v.size(); i++)
        {
            if(v[i].second == nums[i])
                continue;
            int idx = mp[v[i].second];
            mp[v[i].second] = i;
            mp[nums[i]] = idx;
            swap(nums[i],nums[idx]);
            ans++;
        }return ans; 
    }
};