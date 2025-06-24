class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {

        int lastidx = -1; 
        vector<int> ans;
        for(int i = 0; i< nums.size(); i++)
        {
            if(lastidx == nums.size()-1)
                return ans; 
            if(nums[i] == key)
            {
                int val1 = max(0,i-k);
                int val2 = min((int)nums.size()-1, i+k);
                if(lastidx >= val2)
                    continue;
                if(lastidx < i)
                {
                    if(lastidx >= val1)
                        lastidx++;
                    else
                        lastidx= val1;
                    while(lastidx < val2)
                    {
                        ans.push_back(lastidx); lastidx++;
                    }

                    ans.push_back(lastidx);
                }
                else
                {
                   lastidx++;
                   while(lastidx < val2)
                   {
                        ans.push_back(lastidx);
                        lastidx++;
                   }
                    ans.push_back(lastidx);

                }
            }
        }
        return ans; 
        
        
    }
};