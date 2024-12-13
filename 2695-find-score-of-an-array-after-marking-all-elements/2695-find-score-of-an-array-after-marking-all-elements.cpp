class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long ans = 0 ; 
        priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
        for(int i = 0; i< nums.size(); i++)
        {
            pq.push({nums[i],i});
        }
        while(!pq.empty())
        {
            auto cur = pq.top(); pq.pop();
            if(nums[cur.second] != -1)
            {
                ans += cur.first;
                nums[cur.second] = -1;
                if(cur.second-1>=0)
                {
                    nums[cur.second-1] = -1;
                }
                if(cur.second+1 < nums.size())
                {
                    nums[cur.second +1] = -1;
                }
            }
        }return ans; 
        
    }
};