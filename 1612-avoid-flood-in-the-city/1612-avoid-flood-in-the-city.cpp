class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        set<int>st;
        vector<int>ans(rains.size());
        unordered_map<int,int>mp;
        unordered_map<int,int>lastIdx;
        for(int i = 0; i< rains.size(); i++)
        {
            if(rains[i] == 0)
            {
                st.insert(i); continue;
            }
            mp[rains[i]]++;
            
            while(!st.empty() && mp[rains[i]] >1 )
            {
                auto it = st.upper_bound(lastIdx[rains[i]]);
                if(it == st.end())
                    return {};
                ans[*it] = rains[i];
                mp[rains[i]]--;
                st.erase(*it);
            }
            if(mp[rains[i]]> 1)
                return {};
            lastIdx[rains[i]]=i;
            ans[i] = -1;
        }
        for(int i = 0; i< ans.size(); i++)
        {
            if(ans[i] == 0)
                ans[i] = 1;
        }
        return ans; 
        
    }
};