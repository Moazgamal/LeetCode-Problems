class Solution {
public:
    int minDeletion(string s, int k) {
    unordered_map<char,int>mp;
        for(int i = 0; i< s.size(); i++)
            {
                mp[s[i]]++;
            }
        if(mp.size() <=k)
            return 0; 
        int sz = mp.size();
        vector<int>v;
        for(auto x: mp)
            {
                v.push_back(x.second);
            }
        sort(v.begin(), v.end());
        int ops = 0; 
        for(int i = 0; i< v.size(); i++)
            {
                ops += v[i];
                sz--;
                if(sz ==k)
                    return ops;
            }
        return ops;
            
        
    }
};