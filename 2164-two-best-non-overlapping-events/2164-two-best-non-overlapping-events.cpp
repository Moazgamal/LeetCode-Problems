class Solution {
    int BS(int start, vector<vector<int>>&events, int target)
    {
        int pos = -1; int mid = -1;
        int end = events.size()-1;
        while(start <= end)
        {
            mid = start + (end - start)/2;
            if(events[mid][0] > target)
            {
                pos = mid;
                end = mid-1;
            }
            else
            {
                start = mid + 1;
            }
        }
        if(pos != -1)
            return events[pos][0];
        return pos;
    }
public:
    int maxTwoEvents(vector<vector<int>>& events) {

        sort(events.begin(), events.end());
        unordered_map<int,int> maxis;
        int lastmax = 0; 
        for(int i = events.size()-1; i>=0; i--)
        {
            int start = events[i][0];
            int val = events[i][2];
            lastmax = max(lastmax, val);
            maxis[start] = lastmax;
        }
        int ans = 0; 
        for(int i = 0; i< events.size(); i++)
        {
            int idx = BS(i, events, events[i][1]);
           
                ans = max(ans, events[i][2]);
            
            if(idx != -1)
            {
                
                ans = max(ans, events[i][2] + maxis[idx]);
            }

        }return ans; 
        
    }
};