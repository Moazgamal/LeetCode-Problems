class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        for(int i = 0; i< nums.size(); i++)
        {
            pq.push({nums[i], i});
        }
        while(!pq.empty() && k--)
        {
            auto cur = pq.top(); pq.pop();
            nums[cur.second] = multiplier*cur.first;
            pq.push({multiplier*cur.first, cur.second});
        }return nums;
        
    }
};