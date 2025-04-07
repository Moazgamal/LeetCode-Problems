class Router {
public:
queue< pair< pair<int,int>,int> > p;
unordered_map<int, vector<int>>mp;
unordered_map<int, int>mp2;
map<vector<int>, int> mpp;
int x = 0; 
int y = 0; 
    Router(int memoryLimit) {
        x = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(mp.count(destination)==0)
        {
            if(y == x)
            {
                    auto i = p.front(); p.pop();
                    int s = i.first.first;
                    int d = i.first.second;
                    int t = i.second;
                    mpp.erase({s,d,t});
                    mp2[d]++;
                    y--;
            }
            p.push({{source,destination}, timestamp});
            mp[destination].push_back(timestamp);
            mpp[{source,destination,timestamp}]++;
            y++;
            return true;
        }
        else
        {
            if(mpp.count({source,destination,timestamp}))
            {
                return false;
            }
            else
            {
                if(y == x)
                {
                    auto i = p.front(); p.pop();
                    int s = i.first.first;
                    int d = i.first.second;
                    int t = i.second;
                    mp2[d]++;
                    mpp.erase({s,d,t});
                    y--;
                }
                p.push({{source,destination}, timestamp});
                mp[destination].push_back(timestamp);
                mpp[{source,destination,timestamp}]++;
                y++;
            }
        }
        return true;
        
    }
    
    vector<int> forwardPacket() {
        if(p.size()==0)
            return {};
        auto i = p.front(); p.pop();
        int s = i.first.first;
        int d = i.first.second;
        int t = i.second;
        mp2[d]++;
        mpp.erase({s,d,t});
        y--;
        return {i.first.first, i.first.second,i.second};
        
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int cnt = 0; 
        auto right = lower_bound(mp[destination].begin()+mp2[destination] , mp[destination].end(), startTime);
        auto left = upper_bound(mp[destination].begin()+mp2[destination] , mp[destination].end(), endTime);
        return int(left - right);
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */