class Solution {
    void dfs(int indx, unordered_map<int, vector<int>>&mp, vector<int>&indices, vector<int>&values, vector<int>&nums, vector<bool>&vis)
    {
        vis[indx] = true;
        indices.push_back(indx);
        values.push_back(nums[indx]);
        for(int i = 0; i< mp[indx].size(); i++)
        {
            if(!vis[mp[indx][i]])
            {
                dfs(mp[indx][i], mp, indices, values, nums, vis);
            }
        }
    }
public:
    long long maxAlternatingSum(vector<int>& nums, vector<vector<int>>& swaps) {
        long long ans = 0; 
        unordered_map<int, vector<int> > mp;
        for(int i = 0; i< swaps.size(); i++)
        {
            mp[swaps[i][0]].push_back(swaps[i][1]);
            mp[swaps[i][1]].push_back(swaps[i][0]);
        }
        vector<bool>vis(nums.size(), false);
        for(int i = 0; i< nums.size(); i++)
        {
            if(vis[i]==false)
            {
                vector<int>indices;
                vector<int>values;
                dfs(i, mp, indices, values, nums, vis);
                sort(indices.begin(), indices.end());
                sort(values.rbegin(), values.rend());
                int k = 0; 
                for(int j = 0; j< indices.size(); j++)
                {
                    int ind = indices[j];
                    if(ind %2 == 0)
                    {
                        nums[ind] = values[k++];
                    }
                }
                for(int j = 0; j< indices.size() && k< values.size(); j++)
                {
                    int ind = indices[j];
                    if(ind %2 != 0)
                    {
                        nums[ind] = values[k++];
                    }
                }
                
            }
        }
        for(int i = 0; i< nums.size(); i++)
        {
            if(i== 0 || i%2 == 0)
            {
                ans += nums[i];
            }
            else
                ans-= nums[i];
        }return ans; 
    }
};