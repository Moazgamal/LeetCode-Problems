class Solution {
    void fn(string &str, long long &ans, int &n, unordered_map<int,bool>&mp,
    vector<string>&v)
    {
        for(int i = 1; i<=9; i++)
        {
            if(mp[i] == true)
                continue;
            int j = i;
            int sz = (int)str.size();
            if(j+sz>7)
                continue;
            while(j--)
            {
                str.push_back(i+'0');
            }
            v.push_back(str);
            mp[i]=true;
            fn(str,ans,n,mp,v);
            mp[i] = false;
            j=i;
            while(j--)
            {
                str.pop_back();
            }
        }
    }
    void permGen(string &str, long long &ans,int &n, int idx = 0)
    {
        long long h = stoll(str);
        if(h>n)
            ans = min(ans, h);
        for(int i = idx; i<str.size(); i++)
        {
            if(idx != i && str[idx] == str[i])
                continue;
            swap(str[idx], str[i]);
            permGen(str, ans, n, idx+1);
            swap(str[idx], str[i]);
        }
    }
public:
    int nextBeautifulNumber(int n) {
        // if(n == 0)
        //     return 1; 
        long long ans = INT_MAX;
        string str = "";
        unordered_map<int,bool>mp;
        vector<string>v;
        fn(str, ans, n,mp,v);
        for(int i = 0; i< v.size(); i++)
        {
            permGen(v[i],ans, n);
        }
        return ans; 
        
    }
};