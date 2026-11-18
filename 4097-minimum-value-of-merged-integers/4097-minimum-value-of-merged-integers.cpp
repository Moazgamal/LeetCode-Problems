class Solution {
public:
    int minMergedInteger(vector<int>& nums) {

        int maxi = INT_MAX;
        int i = 0; 
        while(i < nums.size()-1)
        {
            string str = to_string(nums[i]);
            string str2 = to_string(nums[i+1]);
            maxi = min(maxi, stoi(str+str2));
            i+=2;
        }return maxi;
    }
};