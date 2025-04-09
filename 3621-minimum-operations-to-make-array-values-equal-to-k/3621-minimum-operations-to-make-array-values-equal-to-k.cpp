class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        if(nums[0]< k)
            return -1;
        set<int>st;
        for(int i = 0; i< nums.size(); i++)
            {
                if(nums[i] == k)
                    continue;
                st.insert(nums[i]);
            }
        return st.size();
        
        
    }
};