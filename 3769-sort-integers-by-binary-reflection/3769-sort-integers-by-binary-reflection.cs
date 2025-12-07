public class Solution {
    private  int fn(int num)
        {
            string str = "";
            while(num >0)
            {
                str+=((num%2).ToString());
                num /=2;
            }
            int j = 0; int newNum = 0; 
            for(int i= str.Length-1; i>=0; j++,i--)
            {
                if(str[i] == '0')
                    continue;
                newNum += (1<<j);
            }
            return newNum;
        }
    public int[] SortByReflection(int[] nums) {
        

        List<Tuple<int,int>>v = new List<Tuple<int,int>>();
        for(int i = 0; i< nums.Length; i++)
        {
            var t = new Tuple<int,int>(fn(nums[i]), nums[i]);
            v.Add(t);
        }
        v.Sort((a, b) =>
        {
            int cmp = a.Item1.CompareTo(b.Item1);
            if (cmp == 0) return a.Item2.CompareTo(b.Item2);
            return cmp;
        });
        int[]ans = new int[nums.Length];
        for(int i = 0; i< v.Count; i++)
        {
            ans[i] = (v[i].Item2);
        }return ans; 
        
    }
}