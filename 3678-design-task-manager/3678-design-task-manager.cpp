

class TaskManager {
public:
    unordered_map<int,pair<int,int>>mp;
    priority_queue<pair<int,int>> pq;
    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0; i< tasks.size(); i++)
        {
            pq.push({tasks[i][2], tasks[i][1]});
            mp[tasks[i][1]] = make_pair(tasks[i][0],tasks[i][2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        pq.push({priority,taskId});
        mp[taskId]= make_pair(userId,priority);
    }
    
    void edit(int taskId, int newPriority) {
        mp[taskId].second = newPriority;
        pq.push({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        mp.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty())
        {
            auto cur = pq.top();
            if(mp.count(cur.second) == 0 || mp[cur.second].second != cur.first)
            {
                pq.pop();
                continue;
            }
            else
            {
                pq.pop();
                int user = mp[cur.second].first;
                mp.erase(cur.second);
                return user;
            }
        }
        return -1;
        
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */