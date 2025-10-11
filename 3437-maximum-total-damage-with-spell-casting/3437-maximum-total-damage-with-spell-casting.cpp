class Solution {
    long long fn(int idx, vector<pair<int,int>>&v, vector<long long>&dp)
    {
        if(idx >= v.size())
            return 0; 
        auto &ret = dp[idx];
        if(ret != -1)
            return ret; 
        long long c1 =  v[idx].first*v[idx].second; 
        long long c2 = fn(idx+1, v, dp);
        if(idx+1 < v.size() && v[idx+1].first > v[idx].first+2)
            c1 += fn(idx+1, v, dp);
        else if(idx+2 < v.size() && v[idx+2].first > v[idx].first+2)
            c1 += fn(idx+2, v, dp);
        else if(idx+3 < v.size() && v[idx+3].first > v[idx].first+2)
            c1 += fn(idx+3, v, dp);
        
        return ret = max(c1, c2);
        
    }
public:
    long long maximumTotalDamage(vector<int>& power) {
        sort(power.begin(), power.end());
        vector<pair<int,int>>v;
        for(int i = 0; i< power.size(); )
        {
            int j = i+1;
            while(j< power.size() && power[j] == power[i])
                j++;

            v.push_back({power[i], j-i});
            i=j;
        }
        vector<long long>dp(v.size()+2, -1);
        long long ans = INT_MIN;
        for(int i = 0; i< v.size(); i++)
        {
            long long coll = (long long)v[i].first*v[i].second;
            
            if(i+1 < v.size() && v[i+1].first > v[i].first+2)
                coll+= fn(i+1, v, dp);
            else if(i+2 < v.size() && v[i+2].first > v[i].first+2)
                coll += fn(i+2, v, dp);
            else if(i+3 < v.size() && v[i+3].first > v[i].first+2)
                coll+=fn(i+3, v, dp);

            ans = max(ans, coll);
        }
        return ans;
        
    }
};