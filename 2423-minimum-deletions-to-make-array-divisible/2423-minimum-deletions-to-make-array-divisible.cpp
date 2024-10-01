class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
sort(nums.begin(), nums.end());
if(nums[0]==1)
    return 0;
        int x = 0; 
        for(int i = 0; i< numsDivide.size(); i++)
        {
            x= __gcd(numsDivide[i], x);
        }
        if(x==1)
            {
                return -1;
            }
        
        for(int i = 0; i< nums.size(); i++)
        {
            if(x%nums[i] ==0)
                return i;
        }
        return -1;
        

        
    }
};