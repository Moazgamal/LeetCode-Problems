class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int i = 0; 
        int sz = nums.size()-1;
        if(sz == 0)
            return nums[0];
        vector<int>newNum;
        while(i<sz)
        {
            while(i< sz)
            {
                newNum.push_back((nums[i]+ nums[i+1])%10);
                i++;
            }
            sz = newNum.size()-1;
            i = 0; 
            if(sz == 0)
                return newNum[0];
            nums= newNum;
            newNum.clear(); 
        }
        return 1;
        
        
    }
};