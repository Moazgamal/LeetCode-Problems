class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {

    int n = nums.size();
        vector<int> result(nums.size(),0);
        for(int i = 0; i< nums.size(); i++)
            {
                int pos = 0; 
                if(nums[i] ==0)
                    result[i] = 0;
                else 
                {
                   int pos = i+nums[i];
                    pos = (pos%n +n)%n;
                    result[i] = nums[pos];
                }
                
            }return result;
        
        
    }
};