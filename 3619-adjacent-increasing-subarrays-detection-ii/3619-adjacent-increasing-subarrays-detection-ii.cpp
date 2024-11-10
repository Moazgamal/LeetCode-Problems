class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 0;
        for(int i = 0; i< nums.size(); i++)
        {
            int j = i+1;
            for(; j< nums.size(); j++)
            {
                if(nums[j] > nums[j-1])
                    continue;
                else
                    break;
            }
            if(j-i <= ans)
            {
                i=j-1;
                continue;
            }
            int m = j+1;
            for(; m< nums.size(); m++)
            {
                if(nums[m]>nums[m-1])
                    continue;
                else
                    break;
            }
            int l1 = j-i;
            int l2 = m-j;
            int v = min(l1,l2);
            v = max(v, l1/2);
            v = max(v, l2/2);
            cout<<l1<<" "<<l2<<"\n";
            ans=max(ans, v);
            if(l1>l2)
                i=m-1;
            else
                i = j-1;
            
        }
        
        return ans;
        
    }
};