class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        if(events.size() ==1)
                return events[0][0];
        int ans = events[0][1];
        int t = events[0][1];
       
        int ians = events[0][0];
        for(int i = 1; i< events.size(); i++)
            {
                int diff = events[i][1] - events[i-1][1];
                if(diff > ans)
                {
                    ans = diff;
                    ians = events[i][0];
                }
                else if(diff == ans)
                {
                    ians = min(ians, events[i][0]);
                }
            }return ians;
        
    }
};