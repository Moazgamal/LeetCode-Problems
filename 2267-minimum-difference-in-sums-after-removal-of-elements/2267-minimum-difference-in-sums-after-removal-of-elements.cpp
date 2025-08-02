class Solution {
public:
    long long minimumDifference(vector<int>& nums) {

        long long ans = LLONG_MAX;
        priority_queue<long long>pq1;
        priority_queue<long long, vector<long long> , greater<long long>>pq2;
        long long sum1 = 0; 
        long long sum2 = 0; 
        int sz = (int)nums.size();
        int block = sz/3;
        int i =0; 
        while(i< block)
        {
            sum1 += nums[i];
            pq1.push(nums[i]);
            i++;
        }
        int k = sz-1;
        while(k >= sz-block)
        {
            sum2 += nums[k];
            pq2.push(nums[k]);

             k--;
        }
        vector<long long> dp1(block+1);
        vector<long long> dp2(block+1);
        for(int j = 0; j< dp1.size(); j++)
        {
            dp1[j] = sum1;
            if(nums[i] < pq1.top())
            {
                sum1 -= pq1.top(); pq1.pop(); pq1.push(nums[i]);
                sum1 += nums[i];
                cout<<nums[i]<<" iiiii\n";
            }
                i++;
        }
        for(int j = 0; j< dp2.size(); j++)
        {
            dp2[j] = sum2;
            
            if(nums[k] > pq2.top())
            {
                sum2 -= pq2.top(); pq2.pop(); pq2.push(nums[k]);
                sum2 += nums[k];
                cout<<nums[k]<<" kkkkkkkk\n";
            }
                k--;
        }
        int ss = dp2.size()-1;
        int f = 0; 
        int u = block+1 ;
        while(u--)
        {
            long long val1 = dp1[f];
            f++;
            long long val2 = dp2[ss];
            ss--;
            ans = min(ans, val1-val2);
        }
        return ans; 
        
    }
};