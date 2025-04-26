class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0; 
        int j = -1;
        int lastmin = -1;
        int lastmax = -1; 
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] < minK || nums[i] > maxK)
            {
                j = i ;
                lastmin = -1; 
                lastmax = -1; 
                continue;
            }
            if(nums[i] == minK && nums[i] == maxK)
            {
                if(j == -1)
                    ans+= (i+1);
                else
                    ans+= (i-j);

                lastmin= i;
                lastmax=i;
                continue;
            }
            
            if(nums[i] != minK && nums[i] != maxK)
            {
                if(lastmin != -1 && lastmax != -1)
                {
                    int idx = min(lastmin, lastmax);
                    if(j == -1)
                        ans+= (idx+1);
                    else
                        ans+=(idx-j);
                }
            }
            else if(nums[i] == minK  )
            {
                if(lastmax != -1)
                {
                    if(j == -1)
                        ans+= (lastmax+1);
                    else
                        ans+=(lastmax-j);
                }
                lastmin = i;
            }
            else if(nums[i] == maxK )
            {
                if(lastmin != -1 )
                {
                    if(j == -1)
                        ans+= (lastmin+1);
                    else
                        ans+=(lastmin-j);
                }
                lastmax = i;
            }
        }
        return ans;
        
    }
};