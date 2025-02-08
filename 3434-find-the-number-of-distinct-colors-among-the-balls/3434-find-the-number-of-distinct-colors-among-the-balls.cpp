class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int>mp;
        unordered_map<int,int>mp2;
        int cnt = 0; 
        vector<int> result(queries.size(),0);
        for(int i =0; i< queries.size(); i++)
        {
            int color = queries[i][1];
            int node = queries[i][0];
            int oldcolor = -1; 
            if(mp2.count(node) !=0)
                oldcolor = mp2[node];
            if(oldcolor == -1)
            {
                mp[color]++;
                if(mp[color]==1)
                    cnt++;
                mp2[node] = color;
            }
            else
            {
                if(oldcolor != color)
                {
                    mp[oldcolor]--;
                    if(mp[oldcolor] ==0)
                        cnt--;
                    mp[color]++;
                    if(mp[color] ==1)
                        cnt++;
                    mp2[node] = color;
                }

            }
            result[i] = cnt;
        }return result;
        
    }
};