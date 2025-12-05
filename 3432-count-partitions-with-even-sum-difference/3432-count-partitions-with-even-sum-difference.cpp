class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum = 0; 
        for(auto it: nums)
            sum+=it;
        int ans = 0; 
        int cur = 0; int i = 0; 
        for(auto it: nums)
        {
            cur+=it;
            if(abs(cur-(sum-cur))%2 ==0)
                ans++;
           i++;
           if(i == nums.size()-1)
            break;
        }return ans; 
        
    }
};