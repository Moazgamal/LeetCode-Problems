class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0; 
        stack<int>st;
        vector<int>nextSmaller(nums.size(), -1);
        for(int i = 0; i< nums.size(); i++)
        {
            if(st.empty())
            {
                st.push(i); continue;
            }
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] == 0)
            {
                continue;
            }
            ans++;
            int curr = i;
            while(nextSmaller[curr]  != -1 &&  nums[nextSmaller[curr]] == nums[i])
            {
                nums[nextSmaller[curr]] = 0; 
                curr = nextSmaller[curr];
            }
        }
        return ans; 
        
    }
};