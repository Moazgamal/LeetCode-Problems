class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int ans=1;
        vector<int> vis (1000002,0);
        for(int i=0;i <intervals.size();i++)
        {
            
            vis[intervals[i][0]]++;
            ans=max(ans,vis[intervals[i][0]]);
            vis[intervals[i][1]+1]--;
            
        }
        int prefix =0;
        for(int i=0;i <vis.size();i++)
        {
            
            ans=max(ans,prefix);
            prefix+=vis[i];
        }
        
        return max(ans,prefix);
    }
};