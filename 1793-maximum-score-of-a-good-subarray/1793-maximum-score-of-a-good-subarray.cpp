class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        vector<int>nextSmaller(nums.size(), nums.size());
        vector<int>beforeSmaller(nums.size(), -1);
        stack<int>st;
        for(int i = 0; i < nums.size(); i++)
        {
            while(!st.empty() && nums[i] < nums[st.top()])
            {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        stack<int>st2;
        for(int i = nums.size()-1; i >= 0; i--)
        {
            while(!st2.empty() && nums[i] < nums[st2.top()])
            {
                beforeSmaller[st2.top()] = i;
                st2.pop();
            }
            st2.push(i);
        }
        long long ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            long long first = beforeSmaller[i];
            long long second = nextSmaller[i];
            // cout<<i<<" "<<first<<" "<<second<<"\n";
            if(i <= k)
            {
                if(second == (int)nums.size() && second-1>=k)
                    ans = max(ans, nums[i]*((long long)nums.size()-1-i+1));

                if(second-1 >=k)
                    ans = max(ans, nums[i]*(second-1-i+1));
                
                
                if(first == -1)
                {
                    if(second-1>=k)
                        ans = max(ans, nums[i]*(second-1-0+1));
                }
                else if(first+1<=k)
                {
                    if(second-1>=k)
                        ans = max(ans, nums[i]*(second-1-first-1+1));
                }

            }           
            else
            {
                if(first == -1)
                    ans = max(ans, nums[i]*(second));
                else if(first+1<=k)
                    ans = max(ans, nums[i]*(second-first-1));
            }
            // cout<<i<<" "<<ans<<"\n";
        }
        return ans; 
    }
};