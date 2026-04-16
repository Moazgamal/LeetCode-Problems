class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int,set<int>>mp;
        for(int i = 0; i< nums.size(); i++)
            {
                mp[nums[i]].insert(i);
            }
        vector<int> res(queries.size()); 
        for(int i =0; i< queries.size(); i++)
            {
                int num = nums[queries[i]];
                auto it = mp[num].find(queries[i]);
                auto nextit = next(it);
                    if(mp[num].size()==1)
                    {
                        res[i] = -1;
                        continue;
                    }
                if(nextit != mp[num].end())
                {
                    res[i] = *nextit - *it;
                    int sz = nums.size()-1;
                    auto j = *std::prev(mp[num].end()) ;
                    int u = *it +1;
                    u = u + (sz- j);
                    res[i] = min(res[i],u);
                }
                else
                {
                    int firstidx = *(mp[num].begin());
                    int sz = nums.size();
                    int k = sz-*it;
                    k = k+ firstidx;
                    res[i] = k;
                }
                if(it != mp[num].begin())
                {
                    auto previous = prev(it);
                    res[i] = min(res[i], *it - *previous);
                }
            }
        return res;
        
    }
};