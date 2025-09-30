class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int i = 0; 
        int sz = nums.size()-1;
        if(sz == 0)
            return nums[0];
        while(i<sz)
        {
            vector<int>newNum;
            int j = i; 
            while(j< sz)
            {
                newNum.push_back((nums[j]+ nums[j+1])%10);
                j++;
            }
            sz = newNum.size()-1;
            i = 0; 
            if(sz == 0)
                return newNum[0];
            nums= newNum;
        }
        return 1;
        
        
    }
};