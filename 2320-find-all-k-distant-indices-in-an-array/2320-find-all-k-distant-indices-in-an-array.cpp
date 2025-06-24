class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        int lastidx = -1; 
        vector<int> ans;
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] == key)
            {
                int val1 = max(0,i-k);
                int val2 = i+k;
                if(lastidx >= val2)
                    continue;
                if(lastidx < i)
                {
                    if(lastidx >= val1)
                        lastidx++;
                    else
                        lastidx= val1;
                    while(lastidx < val2 && lastidx < nums.size())
                    {
                        ans.push_back(lastidx); lastidx++;
                    }

                    if(lastidx< nums.size())
                        ans.push_back(lastidx);
                    else
                        return ans; 
                }
                else
                {
                   lastidx++;
                   while(lastidx < val2 && lastidx<nums.size())
                   {
                        ans.push_back(lastidx);
                        lastidx++;
                   }
                   if(lastidx < nums.size())
                        ans.push_back(lastidx);
                    else
                        return ans; 

                }
            }
        }
        return ans; 
        
        
    }
};