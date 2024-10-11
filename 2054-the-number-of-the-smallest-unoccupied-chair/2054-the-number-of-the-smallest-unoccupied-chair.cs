public class Solution {
    public int SmallestChair(int[][] times, int targetFriend) {
        PriorityQueue<int,int> pq = new PriorityQueue<int,int>();


        Dictionary<int,int>mp = new Dictionary<int,int>();
        Dictionary<int,List<int>> mp2 = new Dictionary<int,List<int>>();

        int targetindex =times[targetFriend][0];
        for(int i = 0; i< times.Length; i++)
        {
           mp[times[i][0]]= times[i][1];
           
        }
        int curavchair = 0;
        for(int i = 1; i<= targetindex; i++)
        {
            if(mp2.ContainsKey(i) == true)
            {
                foreach(var x in  mp2[i])
                {
                    pq.Enqueue(x,x);
                }
            }
            if(mp.ContainsKey(i) == true)
            {
                if(pq.Count >0)
                {
                    if(i == targetindex)
                        return pq.Peek();
                    int end = mp[i];
                    if(mp2.ContainsKey(end))
                        mp2[end].Add(pq.Peek());
                    else
                        mp2.Add(end, new List<int>(){pq.Peek()});
                    pq.Dequeue();
                    
                }
                else
                {
                    if(i== targetindex)
                        return curavchair;
                    int end = mp[i];
                    if(mp2.ContainsKey(end))
                        mp2[end].Add(curavchair);
                    else
                        mp2.Add(end, new List<int>(){curavchair});
                    
                    curavchair++;
                    
                }
            }
            
        }
        return 0;
        

        
    }
}