class Solution {
    int bs(int val, vector<pair<int,int>>&v, int start, int end)
    {
        int mid = -1; int pos = -1;
        while(start <= end)
        {
            mid = start + (end-start)/2;
            if((v[mid].first) > val+2)
            {
                pos = mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        return pos;
    }
    long long fn(int idx, vector<pair<int,int>>&v, vector<long long>&dp)
    {
        if(idx >= v.size())
            return 0; 
        auto &ret = dp[idx];
        if(ret != -1)
            return ret; 
        long long c1 =  v[idx].first*v[idx].second; 
        long long c2 = fn(idx+1, v, dp);
        int indx = bs(v[idx].first, v, idx+1, v.size()-1);
        if(indx != -1)
            c1 += (fn(indx, v, dp));
        
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
            {
                j++;
            }
            v.push_back({power[i], j-i});
            i=j;
        }
        vector<long long>dp(v.size()+2, -1);
        long long ans = INT_MIN;
        for(int i = 0; i< v.size(); i++)
        {
            int indx = bs(v[i].first, v, i+1, v.size()-1);
            long long coll = (long long)v[i].first*v[i].second;
            if(indx != -1)
            {
                coll+= fn(indx, v, dp);
                
            }
            ans = max(ans, coll);
        }
        return ans;
        
    }
};