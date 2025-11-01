class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int>ans;
        int i = 0; 
        while(i < nums.size())
        {
            if(nums[i] == i)
                continue;
            int j = i;
            while(nums[j] != j)
            {
                int idx = nums[j];
                if(nums[idx] == idx)
                {
                    if(ans.size()==1 && ans[0]!=idx
                    || ans.size() == 2 && ans[0]!= idx && ans[1] != idx
                    || ans.size() == 0)
                        ans.push_back(idx);
                    break;
                }
                else
                {
                    int temp = nums[idx];
                    nums[idx] = idx;
                    nums[j] = temp;
                }
            }
            i++;
        }return ans; 

        
    }
};