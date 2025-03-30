class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>mp;
        unordered_map<char,int>mp2;
        for(int i =0; i< s.size(); i++)
        {
            if(mp.count(s[i])==0)
            {
                mp[s[i]]=i;
                mp2[s[i]]=i;
            }
            else
            {
                mp2[s[i]]= i; 
            }
        }
        int ans = 0; 
        int maxidx=-1;
        vector<int>v;
        for(int i = 0; i< s.size(); i++)
        {
            if(i > maxidx)
            {
                ans++;
                v.push_back(i);
                
            }
            maxidx = max(maxidx, mp2[s[i]]);

        }
        vector<int>res;
        for(int i = 0; i< v.size(); i++)
        {

            if(i == v.size()-1)
            {
                res.push_back(s.size() - v[i]);
            }
            else
            {
                res.push_back(v[i+1]-v[i]);
            }
        }
        return res; 

    }
};