class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0; 
        for(int i = 0; i< 32; i++)
        {
            int cnt = 0; 
            int x = (1<<i);
            for(int j = 0; j< nums.size(); j++)
            {
                if((x & nums[j]) != 0)
                {
                    cnt++;
                }
            }
            if(cnt %3 !=0)
            {
                ans+= (x);
            }
        }return ans; 
    }
};