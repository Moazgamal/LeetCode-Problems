class Solution {
public:
    int checkWays(vector<vector<int>>& pairs) {

        unordered_map<int, vector<int>>graph;
        unordered_map<int, unordered_map<int, bool>>graph2;
        unordered_set<int>st;
        bool uu = false;
        int c = 0; 
        for(int i = 0; i < pairs.size(); i++)
        {
            graph[pairs[i][0]].push_back(pairs[i][1]);
            graph[pairs[i][1]].push_back(pairs[i][0]);
            graph2[pairs[i][1]][pairs[i][0]]=true;
            graph2[pairs[i][0]][pairs[i][1]]=true;
            st.insert(pairs[i][0]);
            st.insert(pairs[i][1]);
        }
        for(auto &U: graph)
        {
            if(U.second.size() == st.size()-1)
            {
                uu = true; c++;
                if(c > 1)
                    return 2;
            }
        }
        if(uu == false)
            return 0; 
        if(c >1)
            return 2;
        unordered_map<int, unordered_map<int, bool>>Anc;
        bool flag = false;
        for(auto &x: graph)
        {
            for(auto &y: x.second)
            {
                if(graph[y].size() < x.second.size())
                    continue;
                int cnt = 1; 
                if(graph[y].size() >= x.second.size())
                {
                    for(auto &j: x.second)
                    {
                        if(j == y)
                            continue;
                        if(graph2[y][j] == true)
                            cnt++;
                    }
                    if(cnt < x.second.size())
                    {
                        // cout<<y<<" "<<x.first<<" "<<cnt<<" sss\n";
                        return 0; 
                    }
                    if(graph[y].size() == x.second.size() && cnt == x.second.size())
                    {
                        // cout<<x.first<<" "<<y<<" flag\n";
                        flag = true;
                    }
                    if(cnt == x.second.size() && graph[y].size() > x.second.size())
                        Anc[x.first][y]=true;

                    if(Anc[y][x.first] == true)
                    {
                        // cout<<y<<" "<<x.first<<" \n";
                        return 0; 
                    }
                }
            }
            if(Anc[x.first].size() == 0 && graph[x.first].size() != st.size()-1)
                return 0 ;


        }
        if(flag)
            return 2;
        return 1; 
    }
};