class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        
        for(int i = 0; i< tasks.size(); i++)
        {
            int diff = tasks[i][1]-tasks[i][0];
            tasks[i][0]=diff;
        }
        int cur = 0;
        sort(tasks.rbegin(), tasks.rend());
        //  [](const vector<int>& a, const vector<int>& b) {
        //      return a[1] < b[1];
        //  });
        
        int collect = 0; 
        for(int i = 0; i< tasks.size(); i++)
        {
            int start = tasks[i][1];
            int duration = tasks[i][0];
            if(start > cur)
            {
                collect += (start-cur);
                cur = duration;
            }
            else
                cur-= (start-duration);
        }
        
        return collect;
    }
};