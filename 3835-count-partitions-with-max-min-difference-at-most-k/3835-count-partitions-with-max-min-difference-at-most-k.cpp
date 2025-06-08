const int MOD= 1e9+7;
class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        vector<long long> dp(nums.size()+1);
        dp[0]=1;
        vector<long long> prefix(nums.size()+1);
        prefix[0]=1;
        deque<int> maxi;
        deque<int>mini;
        int l = 0; 
        for(int r = 0; r<nums.size(); r++)
            {
                while(!maxi.empty() && nums[maxi.back()]<nums[r])
                    maxi.pop_back();
                maxi.push_back(r);
                while(!mini.empty() && nums[mini.back()]>=nums[r])
                    mini.pop_back();
                mini.push_back(r);
                while(nums[maxi.front()] - nums[mini.front()]>k)
                    {
                        if(maxi.front() == l)
                            maxi.pop_front();
                        if(mini.front() == l)
                            mini.pop_front();
                        l++;
                    }
                dp[r+1] = (prefix[r]- (l>0?prefix[l-1]:0)+MOD)%MOD;
                prefix[r+1] = (prefix[r]+dp[r+1])%MOD;
            }
        return dp[nums.size()];
    }
};