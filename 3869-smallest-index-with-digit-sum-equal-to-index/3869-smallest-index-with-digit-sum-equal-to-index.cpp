class Solution {
public:
    int smallestIndex(vector<int>& nums) {

        for(int i = 0;i < nums.size(); i++)
        {
            string s = to_string(nums[i]);
            int sum = 0; 
            for(int j = 0; j< s.size(); j++)
            {
                sum += (s[j] -'0');
            }
            if(sum == i)
                return i;
        }return -1;
        
    }
};