class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {

        vector<int>v(heights.size(), heights.size());
        
        stack<int>st;
        for(int i = 0; i< heights.size(); i++)
        {
            if(st.empty())
            {
                st.push(i); continue;
            }
            while(!st.empty() && heights[i]> heights[st.top()])
            {
                v[st.top()] = i; 
                st.pop();
            }
            st.push(i);
        }
        vector<int>ans(heights.size(), 0); 
        for(int i =0; i< heights.size()-1; i++)
        {
            int acc = 0; 
            if(heights[i+1]> heights[i])
            {
                acc++;
                ans[i] = acc;
                continue;
            }
            int idx = v[i];
            int idx2 = v[i+1];
            while(idx2 <= idx && idx2< heights.size())
            {
                acc++;
                idx2 = v[idx2];
            }
            ans[i] = acc+1;
        }
        return ans; 
        
    }
};