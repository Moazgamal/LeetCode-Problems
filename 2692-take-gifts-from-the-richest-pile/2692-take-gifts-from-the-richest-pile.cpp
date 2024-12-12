class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0; 
        priority_queue<long long>pq;
        for(int i = 0; i< gifts.size(); i++)
        {
            pq.push(gifts[i]);
        }
        while(!pq.empty() && k-- > 0)
        {
            long long cur = pq.top();
            pq.pop();
            if(cur>0)
                pq.push(floor(sqrt(cur)));
            else
                break;
        }
        while(!pq.empty())
        {
            ans += pq.top(); pq.pop();
        }
        return ans; 
        
    }
};