class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_map<int,int>mp;
        for(int i = 0; i< x.size(); i++)
        {
            if(mp.count(x[i]) ==0)
                mp[x[i]]= y[i];
            else
                mp[x[i]]= max(mp[x[i]], y[i]);
        }
        vector<int> v;
        for(auto j : mp)
        {
            v.push_back(j.second);
        }
        sort(v.rbegin(), v.rend());
        if(v.size() < 3)
            return -1;
        return v[0]+v[1]+v[2];
        
    }
};