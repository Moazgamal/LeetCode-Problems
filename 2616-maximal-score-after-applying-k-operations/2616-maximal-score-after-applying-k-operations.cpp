class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue <long long> pq; 
        for(int i = 0; i< nums.size(); i++)
        {
            pq.push(nums[i]);
        }long long ans = 0;
        while(k--)
        {
            ans += (pq.top());
            int m = pq.top();
            double m2 = pq.top();
            m= m/3;
            m2 = m2/3;
            if(m!=m2)
                m= m+1;
            pq.pop();
            
            pq.push(m);
        }return ans ;

        
    }
};