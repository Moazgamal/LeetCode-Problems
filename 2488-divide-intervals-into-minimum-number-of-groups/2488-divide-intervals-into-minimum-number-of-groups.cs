public class Solution {
    public int MinGroups(int[][] intervals) {


        int ans=1;
        int[] vis = new int[1000002];
        for(int i=0;i <intervals.Length;i++)
        {
            
            vis[intervals[i][0]]++;
            ans=int.Max(ans,vis[intervals[i][0]]);
            vis[intervals[i][1]+1]--;
            
        }
        int prefix =0;
        for(int i=0;i <vis.Length;i++)
        {
            
            ans=int.Max(ans,prefix);
            prefix+=vis[i];
        }
        
        return int.Max(ans,prefix);
        
    }
}