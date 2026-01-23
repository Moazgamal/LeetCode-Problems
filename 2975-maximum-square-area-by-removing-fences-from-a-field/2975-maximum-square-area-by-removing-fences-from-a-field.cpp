class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(m);
        vFences.push_back(n);
        long long ans = 0;
        int MOD= 1e9+7;
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_map<long long,bool>mp1;
        unordered_map<long long,bool>mp2;

        for(int j = 0; j< hFences.size(); j++)
            mp1[hFences[j]-1]=true;

        for(int j = 0; j< vFences.size(); j++)
            mp2[vFences[j]-1]=true;

        for(int j = 0; j< hFences.size(); j++)
            for(int i = j+1; i< hFences.size(); i++)
                mp1[hFences[i]-hFences[j]]=true;

        for(int j = 0; j< vFences.size(); j++)
            for(int i = j+1; i< vFences.size(); i++)
                mp2[vFences[i]-vFences[j]]=true;

        for(auto &u: mp1)
            if(mp2.count(u.first) >0)
                ans = max(ans, (u.first*u.first));

        if(ans == 0)
            return -1; 
        return ans%MOD;
    }
};