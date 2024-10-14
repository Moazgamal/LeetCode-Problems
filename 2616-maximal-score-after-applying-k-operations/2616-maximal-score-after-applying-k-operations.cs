public class Solution {
    public long MaxKelements(int[] nums, int k) {
        PriorityQueue <int,int> pq  = new PriorityQueue<int,int>(Comparer<int>.Create((a, b) => b-a)); 
        for(int i = 0; i< nums.Length; i++)
        {
            pq.Enqueue(nums[i],nums[i]);
        }long  ans = 0;
        while(k-- > 0)
        {
            ans += (pq.Peek());
            Console.WriteLine(pq.Peek());
            int m = pq.Peek();
            double m2 = pq.Peek();
            m= m/3;
            m2 = m2/3;
            if(m!=m2)
                m= m+1;
            pq.Dequeue();
            
            pq.Enqueue(m,m);
        }return ans ;
        
        
    }
}