class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st; int i = 0 ;
        while(i < prices.size())
        {
            while(!st.empty() && prices[st.top()] >= prices[i])
            {
                prices[st.top()] -= prices[i];
                st.pop();
            }
            st.push(i); i++; 
        }return prices;
    }
};