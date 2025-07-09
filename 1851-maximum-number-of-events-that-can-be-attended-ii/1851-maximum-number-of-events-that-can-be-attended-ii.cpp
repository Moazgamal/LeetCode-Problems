class Solution {
    int BS(int start, int end, int val, vector<vector<int>>&events)
    {
        int mid = -1; int pos = -1; 
        while(start <=end)
        {
            mid = start + (end-start)/2;
            if(events[mid][0] > val)
            {
                pos = mid;
                end = mid -1;
            }
            else
            {
                start  = mid+1; 
            }
        }
        return pos;
    }
    int fn(int idx, vector<vector<int>>&events, vector<vector<int>>&dp,
    int k)
    {
        if(idx>= events.size())
            return 0 ; 
        auto &ret = dp[idx][k];
        if(ret != -1)
            return ret; 
        if(k ==0)
            return 0 ;
        // pick
        int c1 = events[idx][2];
        int next = BS(idx+1, events.size()-1, events[idx][1], events);
        if(next !=-1)
            c1 += fn(next, events, dp, k-1);
        int c2 = fn(idx+1, events, dp, k);
        return ret = max(c1, c2);
    }
public:
    int maxValue(vector<vector<int>>& events, int k) {

        vector<vector<int>>dp(events.size()+1, vector<int>(k+1,-1));
       
        sort(events.begin(), events.end());

        return fn(0, events, dp, k);
        
    }
};