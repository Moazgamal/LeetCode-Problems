class Solution {
    vector<int>fn(vector<int>pattern)
    {
        vector<int>longestk(pattern.size(),0);
        for(int i =1,k=0; i< pattern.size(); i++)
        {
            while(k>0 && pattern[i] != pattern[k])
            {
                k = longestk[k-1];
            }
            if(pattern[i] == pattern[k])
            {
                longestk[i] = ++k;
            }
            else
                longestk[i] =k;
        }return longestk;
    }
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        
        vector<int>longestk = fn(pattern);
        int ans = 0;
        for(int i = 1, k=0; i< nums.size(); i++)
        {
            while(k>0&&(
             (pattern[k]==1 && nums[i]<=nums[i-1]) ||
            (pattern[k]==0 && nums[i] !=nums[i-1]) || 
            (pattern[k] ==-1&& nums[i]>=nums[i-1])
            ))
            {

                
                    k=longestk[k-1];
            }

            if(nums[i] == nums[i-1] && pattern[k] ==0)
                k++;
            else if(nums[i] >nums[i-1] && pattern[k] ==1)
                k++;
            else if(nums[i]< nums[i-1] && pattern[k] ==-1)
                k++;
            if(k== pattern.size())
            {

                ans++;
                
                   k=longestk[k-1];
                    
                cout<<k<<" "<<i<<" \n";
            }
        }
        return ans;
    }
};