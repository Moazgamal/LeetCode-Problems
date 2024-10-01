public class Solution {
    public bool CanArrange(int[] arr, int k) {
        
        Dictionary<int,int> dic = new Dictionary<int,int>();
        for(int i = 0; i< arr.Length; i++)
        {
            int rem = ((arr[i]%k)+k)%k;
            if(dic.ContainsKey(rem))
                dic[rem]++;
            else
                dic.Add(rem,1);
        }
        foreach(var x in dic)
        {
            if(x.Key ==0 && x.Value %2 !=0)
                return false;
            if(x.Key !=0 && (!dic.ContainsKey(k-x.Key) || dic[k-x.Key] != x.Value))
                return false;
        }return true;
        
    }
}