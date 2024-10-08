class Solution {
public:
    int minSwaps(string s) {
        

        stack<char> st;
        vector<int> indices;
        for(int i = s.size()-1; i>=0; i--)
        {
            if(s[i]=='[')
            {
                indices.push_back(i);
            }
        }
        int j = 0; 
        int swaps = 0; 
        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] == ']' )
            {
                if(!st.empty() && st.top() == '[')
                {
                    st.pop();
                }
                else
                {
                    swap(s[i], s[indices[j++]]);
                    st.push('[');
                    swaps++;
                }
            }
            else
                st.push('[');
        }
        return swaps;
    }
};