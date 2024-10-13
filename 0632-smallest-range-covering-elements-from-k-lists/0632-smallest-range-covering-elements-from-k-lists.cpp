class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
         vector<pair<int,int>> v;
         unordered_map<int,int>mp;
         for(int i = 0; i< nums.size(); i++)
         {
            for(int j = 0; j< nums[i].size(); j++)
            {
                v.push_back({nums[i][j],i});
            }
         }sort(v.begin(), v.end());
         int j = 0;
         int count = 0;
         int minval = 0; int maxval = INT_MAX;
         int ans = INT_MAX;
         for(int end = 0; end<v.size();end++)
         {
            int idx = v[end].second;
            mp[idx]++;
            if(mp[idx] == 1)
                count++;
            if(count == nums.size())
            {
                while(j<=end && count == nums.size())
                {
                    if(ans == v[end].first - v[j].first)
                    {
                        if(minval > v[j].first)
                            minval  = v[j].first;
                    }
                    else if(ans > v[end].first - v[j].first)
                    {
                        maxval = v[end].first;
                        minval = v[j].first;
                        ans = maxval-minval;
                    }
                    int i = v[j].second;
                    mp[i]--;
                    if(mp[i]==0)
                        count--;
                    j++;
                }
            }
         }return {minval, maxval};
        
    }
};