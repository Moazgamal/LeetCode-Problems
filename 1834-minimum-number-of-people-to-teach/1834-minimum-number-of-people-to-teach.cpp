class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        
        unordered_map<int, unordered_set<int> > mp;
        unordered_set<int> st;
        for(int i = 0; i < languages.size(); i++)
        {
            for(int j = 0; j < languages[i].size(); j++)
            {
                mp[i+1].insert(languages[i][j]); st.insert(languages[i][j]);
            }
        }
        vector< pair<int,int> >v;
        for(int i = 0; i< friendships.size(); i++)
        {
            int firstt = friendships[i][0]; int secondd = friendships[i][1];
            bool s = false;
            for(auto x: mp[firstt])
            {
                if(mp[secondd].find(x) != mp[secondd].end())
                {
                    s = true; 
                    break;
                }
            }
            if(!s)
            {
                v.push_back({firstt, secondd});
            }
        }
        int ans = INT_MAX;
        for(auto x: st)
        {
            vector<int> vv; int la = x;
            int cnt = 0; 
            for(int i = 0; i< v.size(); i++)
            {
                int firstF = v[i].first; int secondF = v[i].second;
                if(mp[firstF].find(la) != mp[firstF].end())
                {
                    if(mp[secondF].find(la) != mp[secondF].end())
                    {
                        continue;
                    }
                    else
                    {
                        mp[secondF].insert(la); vv.push_back(secondF); cnt++; continue;
                    }
                }
                else if(mp[secondF].find(la) != mp[secondF].end())
                {
                    if(mp[firstF].find(la) != mp[firstF].end())
                    {
                        continue;
                    }
                    else
                    {
                        mp[firstF].insert(la); vv.push_back(firstF); cnt++; continue;
                    }
                }
                else
                {
                    mp[firstF].insert(la); vv.push_back(firstF);
                    mp[secondF].insert(la); vv.push_back(secondF);
                    cnt += 2;
                }
            }
            for(int j = 0; j< vv.size(); j++)
            {
                mp[vv[j]].erase(la);
            }
            ans = min(ans, cnt); 

        }
        return ans; 
    }
};