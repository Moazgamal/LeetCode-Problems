class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        for(int i =0; i< nums.size()-1; )
        {
            int j = i+3;
            vector<int> v;
            v.push_back(nums[i]);
            int f = i+1;
            while(f<j)
            {
                if((nums[f]-nums[i])>k)
                    return {};
                v.push_back(nums[f]);
                f++;
            }
            ans.push_back(v);
            i=f;
        }  
        return ans;  
        
    }
};