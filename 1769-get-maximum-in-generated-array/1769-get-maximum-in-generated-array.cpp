class Solution {
public:
    int getMaximumGenerated(int n) {
        int ans = 0; 
        vector<int>nums(n+1,-1);
        for(int i = 0; i<= n; i++)
        {
            if(i ==0)
            {
                nums[0]= 0; 
                ans= max(ans, nums[0]);
                int x = i*2;
                int y = i*2+1;
                if(x<=n)
                {
                    nums[x]=max(nums[x],0);
                    ans= max(ans, nums[x]);
                }
                if(y<=n && i+1<=n)
                {
                    nums[y] = max(nums[y],nums[0]+nums[i+1]);
                    ans= max(ans, nums[y]);
                }
            }
            else if(i == 1)
            {
                nums[1] = max(nums[1], 1); 
                ans= max(ans, nums[1]);
                int x = 2*i;
                int y = i*2+1;
                if(x<=n)
                {
                    nums[x]=max(nums[x],nums[1]);
                    ans= max(ans, nums[x]);
                }
                if(y<=n && i+1<=n)
                {
                    nums[y] = max(nums[y],nums[1]+nums[i+1]);
                    ans= max(ans, nums[y]);
                }
            }
            else
            {
                if(nums[i]!=-1)
                {
                    int x = 2*i;
                    int y = i*2+1;
                    if(x<=n)
                    {
                        nums[x]=max(nums[x],nums[i]);
                        ans= max(ans, nums[x]);
                    }
                    if(y<=n && i+1<=n)
                    {
                        nums[y] = max(nums[y],nums[i]+nums[i+1]);
                        ans= max(ans, nums[y]);
                    }
                }
            }
        }
        return ans; 
        
    }
};