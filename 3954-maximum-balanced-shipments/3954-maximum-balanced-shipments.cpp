class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int n = weight.size();
        int r = 0;
        int res = 0;
        stack<int> st;
        while (r < n) 
        {
            while (!st.empty() && weight[st.top()] < weight[r])
                st.pop();
            if (!st.empty() && weight[r] < weight[st.top()]) 
            {
                res++;
                while (!st.empty()) st.pop();
                r++;
                continue;
            }
            st.push(r);
            r++;
        }
        return res;
        
    }
};