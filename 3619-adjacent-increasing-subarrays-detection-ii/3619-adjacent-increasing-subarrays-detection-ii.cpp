class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int ans = 0;
        int l1=-1;
        int cnt = 0; 
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
            int l2 = j-i;
            int v = l1!=-1?min(l1,l2):0;
            if(l1 ==-1)
            {
                l1 = j-i;
            }
            v = max(v, l1/2);
            v = max(v, l2/2);
            ans=max(ans, v);
            i=j-1;
            l1=l2;
        }
        return ans;
    }
};