class Solution {
public:
    bool isTrionic(vector<int>& nums) {
       int i = 0; 
       int j = i+1;
       while(j< nums.size() && nums[j]>nums[j-1])
            j++;
        if(j==nums.size()|| nums[j]==nums[j-1] || j-i==1)
            return false;
        int k = j+1;
        while(k<nums.size() && nums[k]< nums[k-1])
            k++;
        if(k == nums.size() || nums[k]== nums[k-1])
            return false;
        int u = k+1;
        while(u< nums.size() && nums[u]>nums[u-1])
            u++;
        if(u<=nums.size()-1)
            return false;
        return true;
        
        
    }
};