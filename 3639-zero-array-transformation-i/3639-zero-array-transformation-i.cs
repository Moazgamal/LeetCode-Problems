public class Solution {
    public bool IsZeroArray(int[] nums, int[][] queries) {
        Dictionary<int,int>mp = new Dictionary<int,int>();
        for(int i = 0; i< queries.Length; i++)
            {
                if(mp.ContainsKey(queries[i][0]))
                    mp[queries[i][0]]++;
                else
                    mp.Add(queries[i][0],1);
                if(mp.ContainsKey(queries[i][1]+1))
                    mp[queries[i][1]+1]--;
                else
                    mp.Add(queries[i][1]+1,-1);
            }
        int lastv = 0; 
        for(int i = 0; i< nums.Length; i++)
            {
                if(mp.ContainsKey(i))
                    lastv+=mp[i];
                Console.WriteLine(lastv);
                if(nums[i]-lastv>0)
                    return false;
            }
        return true;
        
    }
}