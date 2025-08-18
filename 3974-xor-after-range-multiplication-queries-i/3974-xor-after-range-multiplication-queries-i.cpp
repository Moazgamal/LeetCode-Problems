class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {

        long long ans = 0; 
        const int MOD = 1e9+7;
        for(int i = 0; i< queries.size(); i++)
        {
            int left = queries[i][0]; int right = queries[i][1];
            int k = queries[i][2]; long long v = queries[i][3];
            while(left <= right)
            {
                nums[left] = (nums[left]*v)%MOD;
                left += k;
            }
            if(i == queries.size()-1)
                for(int j = 0; j< nums.size(); j++)
                    ans ^= nums[j];
        }
        return ans; 
        
    }
};