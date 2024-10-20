class Solution {
      int divisor(int number)
    {
        int i;
        for (i = 2; i <=sqrt(number); i++)
        {
            if (number % i == 0)
            {
                return number/i;
            }
        }
        return 1;
    }
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        int mini = nums[nums.size()-1];
        for(int i = nums.size()-2; i>=0; i--)
        {
            if(nums[i] > mini)
            {
                int x = divisor(nums[i]);
                if(x == nums[i] || x==1)
                    {
                        return -1;
                    }
                else if(nums[i]/x > nums[i+1])
                    return -1;
                nums[i] = nums[i]/x;
                if(nums[i] < mini)
                    mini = nums[i];
                ans++;
            }
            else if(nums[i] < mini)
            {
                mini = nums[i];
            }
        }
        
        return  ans;
        
    }
};