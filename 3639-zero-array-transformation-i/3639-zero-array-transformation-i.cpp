class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        unordered_map<int,int>mp;
        for(int i = 0; i< queries.size(); i++)
            {
                mp[queries[i][0]]++;
                mp[queries[i][1]+1]--;
            }
        int lastv = 0; 
        for(int i = 0; i< nums.size(); i++)
            {
                lastv+=mp[i];
                if(nums[i]-lastv>0)
                    return false;
            }
        return true;
        
        
    }
};