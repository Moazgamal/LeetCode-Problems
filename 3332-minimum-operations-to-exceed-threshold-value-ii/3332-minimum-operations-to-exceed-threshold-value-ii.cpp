class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long> , greater<long long>> pq1;
        int op = 0; 
        for(int i = 0; i< nums.size(); i++)
            pq1.push(nums[i]);
        while(!pq1.empty() && pq1.size()>=2)
        {
            if(pq1.top()>= k)
                return op;
            op++;
            long long x = pq1.top(); pq1.pop();
            long long y = pq1.top(); pq1.pop();
            pq1.push(min(x,y)*2+max(x,y));
        } 
        return op;      
        
        
    }
};