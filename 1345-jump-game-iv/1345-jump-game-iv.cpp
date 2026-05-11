class Solution {
public:
    int minJumps(vector<int>& arr) {

        unordered_map<int,vector<int>>mp;
        vector<bool>vis(arr.size(), false);
        for(int i = arr.size()-1; i>=0; i--)
        {
            
                mp[arr[i]].push_back(i);
        }
        
        queue<pair<int,int>>q;
        q.push({0,0});
        vis[0]=true;
        while(!q.empty())
        {
            int sz = q.size();
            while(sz--)
            {
                auto cur = q.front();
                q.pop();
                if(cur.first == arr.size()-1)
                    return cur.second;
                if(cur.first+1 < arr.size() && !vis[cur.first+1])
                {
                    if(cur.first+1 == arr.size()-1)
                        return cur.second+1;
                    q.push({cur.first+1, cur.second+1});
                    vis[cur.first+1]= true;
                }
                if(cur.first-1 >=0 && !vis[cur.first-1])
                {
                    if(cur.first-1 == arr.size()-1)
                        return cur.second+1;
                    q.push({cur.first-1, 1+cur.second});
                    vis[cur.first-1]= true;
                }
                for(auto &x: mp[arr[cur.first]])
                {
                    if(x!=cur.first && !vis[x])
                    {
                        if(x == arr.size()-1)
                            return cur.second+1;
                        vis[x]=true;
                        q.push({x, 1+cur.second});
                    }
                }
                mp[arr[cur.first]].clear();
            }
        }
        return 0; 
    }
};