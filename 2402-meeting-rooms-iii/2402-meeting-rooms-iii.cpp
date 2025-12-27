class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        
        vector<long long> v(n,-1);
        sort(meetings.begin(), meetings.end());
        unordered_map<int,long long>mp;
        int  i = 0; 
        
        for(; i< meetings.size(); i++)
        {
            int start = meetings[i][0];
            int end = meetings[i][1];
            bool m = false;
           for(int j = 0; j< v.size() ; j++)
           {
                if(v[j] <= start)
                {
                    v[j] = end;
                    mp[j]++;
                    m = true;
                    break;
                }
           }
           if(!m)
           {
                long long mini = LLONG_MAX;
                int u = -1;
                for(int j = 0; j< v.size() ; j++)
                {
                    if(v[j] < mini)
                    {
                        mini = v[j];
                        u = j;
                    }
                }
                long long duration = end-start;
                long long s = max((long long)start, v[u]);

                v[u] = s+duration; mp[u]++;
           }
        }
        long long ans = LONG_MIN;
        int room = INT_MAX;
        for(auto x: mp)
        {
            if(x.second > ans)
            {
                ans = x.second;
                room = x.first;
            }
            else if(x.second == ans)
            {
                room = min(room, x.first);
            }
        }return room;
        
    }
};