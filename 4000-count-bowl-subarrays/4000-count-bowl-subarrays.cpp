class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {

        long long ans = 0; 
        vector<int>v(nums.size(), -1);
        stack<int>st;
        for(int i = 0; i< nums.size(); i++)
        {
            if(st.empty())
            {
                st.push(i);
                continue;
            }
            while(!st.empty() && nums[i] > nums[st.top()])
            {
                v[st.top()] = i; 
                st.pop();
            }
            st.push(i);
        }
        for(int i = 0; i< nums.size(); i++)
        {
            
            if(v[i] != -1 && i+1 < nums.size() && v[i+1] != -1 && nums[i]>nums[i+1])
            {
                int next = v[i];
                int j = v[i+1]; 
                while(j< nums.size() && j!=-1 && j<= next)
                {
                    ans++;
                    j = v[j];
                }
            }
            else if(v[i] == -1)
            {
                int j = i+1; 
                while(j< nums.size() && v[j] != -1)
                {
                    ans++; j = v[j];
                }
            }
        }
        return ans; 
        
    }
};