class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0; 
        stack<int>st;
        int sz = (int)nums.size();
        vector<int>nextSmaller(sz, -1);
        int i = 0; 
        while(i< sz)
        {
            if(st.empty())
            {
                st.push(i); i++; continue;
            }
            while(!st.empty() && nums[st.top()] >= nums[i])
            {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
            i++;
        }
        i = 0; 
        while(i < sz)
        {
            if(nums[i] == 0)
            {
                i++;
                continue;
            }
            ans++;
            int curr = i;
            while(nextSmaller[curr]  != -1 &&  nums[nextSmaller[curr]] == nums[i])
            {
                nums[nextSmaller[curr]] = 0; 
                curr = nextSmaller[curr];
            }
            i++;
        }
        return ans; 
        
    }
};