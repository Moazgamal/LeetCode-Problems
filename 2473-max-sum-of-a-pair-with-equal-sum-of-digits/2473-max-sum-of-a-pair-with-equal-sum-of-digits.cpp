class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans = -1;
        unordered_map<int,pair<int,int>>mp;
        for(int i = 0; i< nums.size(); i++)
        {
            string s = to_string(nums[i]);
            int sum = 0; 
            for(int j = 0; j< s.size(); j++)
                sum += (s[j]-'0');
            
            if(mp.count(sum)==0)
                mp[sum].first= nums[i];
            else
            {
                if(nums[i] >= mp[sum].first)
                {
                    mp[sum].second= mp[sum].first;
                    mp[sum].first = nums[i];
                }
                else if(nums[i]>mp[sum].second)
                    mp[sum].second = nums[i];
                    
                ans = max(ans,mp[sum].first + mp[sum].second);
            }
        }
        return ans;
        
    }
};