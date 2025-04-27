class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,set<int>>mp1;
        unordered_map<int,set<int>>mp2;
        int ans = 0; 
        for(int i =0; i< buildings.size(); i++)
            {
                int x = buildings[i][0];
                int y = buildings[i][1];
                mp1[x].insert(y);
                mp2[y].insert(x);
            }
        for(int i =0; i< buildings.size(); i++)
            {
                int x = buildings[i][0];
                int y = buildings[i][1];
                auto it1 = mp1[x].find(y);
                auto it2 = mp2[y].find(x);
                bool s1 = false; bool s2 = false;
                if(it1!= mp1[x].end())
                {
                    if(it1 != mp1[x].begin() && it1 != std::prev(mp1[x].end()))
                    {
                        s1 = true;
                    }
                }
                if(it2!= mp2[y].end())
                {
                    if(it2 != mp2[y].begin() && it2 != std::prev(mp2[y].end()))
                    {
                        s2 = true;
                    }
                }
                if(s1 && s2)
                    ans++;
                
            }
        return ans;
        
    }
};