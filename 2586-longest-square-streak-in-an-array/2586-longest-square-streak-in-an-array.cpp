class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        map<long long,int> mp;
        for(int i = 0; i<nums.size(); i++)
        {
            mp[nums[i]]++;
        }
        int ans = 1; 
        for(auto x: mp)
        {
            long long first = x.first;
            int cnt = 1;
            while(mp.count(first*first) >0)
            {
                cnt++;
                mp.erase(first*first);
                first = first*first;
            }
            ans = max(ans, cnt);

        }
        if(ans ==1)
            return -1;
        return ans;
        
    }
};