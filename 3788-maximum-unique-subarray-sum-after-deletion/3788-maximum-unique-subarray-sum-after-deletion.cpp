class Solution {
public:
    int maxSum(vector<int>& nums) {
        int ans= 0; 
        unordered_set<int>st;
        for(int i=0; i< nums.size(); i++)
            {
                st.insert(nums[i]);
            }
        int sz = st.size();
        int cnt = 0; 
        for(auto x: st)
            {
                if(x<=0)
                    continue;
                cnt++;
                ans+= x;
            }
        if(cnt ==0)
        {
            int mini = INT_MIN;
            for(auto x: st)
                {
                    mini= max(mini, x);
                }
            return mini;
        }
        return ans;
        
    }
};