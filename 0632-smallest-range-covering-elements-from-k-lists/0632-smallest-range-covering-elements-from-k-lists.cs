public class Solution {
    public int[] SmallestRange(IList<IList<int>> nums) {
        List<Tuple<int,int>> v = new List<Tuple<int,int>>();
         Dictionary<int,int>mp = new Dictionary<int,int>();
         for(int i = 0; i< nums.Count(); i++)
         {
            for(int w = 0; w< nums[i].Count(); w++)
            {
                Tuple<int,int> t  = new Tuple<int,int>(nums[i][w],i);
                
                v.Add(t);
            }
         }v= v.OrderBy(i => i.Item1).ToList();
         int j = 0;
         int count = 0;
         int minval = 0; int maxval = int.MaxValue;
         int ans = int.MaxValue;
         for(int end = 0; end<v.Count();end++)
         {
            int idx = v[end].Item2;
            if(mp.ContainsKey(idx))
                mp[idx]++;
            else
                mp.Add(idx,1);
            if(mp[idx] == 1)
                count++;
            if(count == nums.Count())
            {
                while(j<=end && count == nums.Count())
                {
                    if(ans == v[end].Item1 - v[j].Item1)
                    {
                        if(minval > v[j].Item1)
                            minval  = v[j].Item1;
                    }
                    else if(ans > v[end].Item1 - v[j].Item1)
                    {
                        maxval = v[end].Item1;
                        minval = v[j].Item1;
                        ans = maxval-minval;
                    }
                    int i = v[j].Item2;
                    mp[i]--;
                    if(mp[i]==0)
                        count--;
                    j++;
                }
            }
         }

         return new int[] {minval,maxval};
        
    }
}