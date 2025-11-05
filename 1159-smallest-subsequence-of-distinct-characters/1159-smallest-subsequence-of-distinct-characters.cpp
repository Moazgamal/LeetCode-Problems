class Solution {
public:
    string smallestSubsequence(string s) {
        vector<vector<int>>v(s.size(), vector<int>(26,0));
        vector<int>x(26,0);
        vector<vector<int>>ind(26);
        int sz = 0; 
        for(int i =0; i< s.size(); i++)
        {
            if(x[s[i]-'a'] == 0)
            {
                sz++;
            }
            x[s[i]-'a']++;
            v[i]= x;
            ind[s[i]-'a'].push_back(i); 
        }
        string ans = "";
        vector<bool>vis(26, false);
        int lastidx = -1; 
        while((int)ans.size() < sz)
        {
            for(int i = 0; i< 26; i++)
            {
                if(ind[i].size()==0)
                    continue;
                if(vis[i] == false)
                {
                    bool valid = true;
                    auto idx = upper_bound(ind[i].begin(), ind[i].end(), lastidx);
                    if(idx == ind[i].end())
                        continue;
                    for(int c = 0; c< 26; c++)
                    {
                        if(vis[c])
                            continue;
                        if(c == i)
                            continue;
                        if(ind[c].size()==0)
                            continue;
                        int val = v[v.size()-1][c] - v[*idx][c];
                        if(val ==0)
                        {
                            valid = false; break;
                        }
                    }
                    if(valid)
                    {
                        vis[i] = true; 
                        ans.push_back(i+'a');
                        lastidx= *idx;
                        break;
                    }
                }
            }
        }return ans; 
    }
};












    // bool fn(vector<vector<int>>&mp, vector<bool>&vis,string &ans,
    // int lastidx, int &sz)
    // {
    //     if((int)ans.size() == sz)
    //     {
    //         return true; 
    //     }
    //     for(int i = 0; i< mp.size(); i++)
    //     {
    //         if(mp[i].size() == 0)
    //             continue;
    //         if(vis[i] == false)
    //         {
    //             auto u = upper_bound(mp[i].begin(), mp[i].end(),
    //             lastidx);
    //             if(u == mp[i].end())
    //             {
    //                 return false;
    //             }
    //             vis[i] = true; 
    //             ans.push_back(i+'a');
    //             bool n = fn(mp, vis, ans, *u, sz);
    //             if(n == true)
    //                 return true; 
    //             vis[i] = false;
    //             ans.pop_back();
    //         }
    //     }
    //     return false;
    // }









        // vector<bool>vis(26, false);
        // vector<vector<int>>mp(26);
        // int sz = 0; 
        // for(int i = 0; i< s.size(); i++)
        // {
        //     if(mp[s[i]-'a'].size()==0)
        //     {
        //         sz++;
        //     } 
        //     mp[s[i]-'a'].push_back(i);
        // }
        // string ans = "";
        // fn(mp, vis, ans, -1, sz);
        // return ans; 