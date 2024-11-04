class Solution {
public:
    string compressedString(string word) {
        stack<pair<char,int>>st;
        st.push({word[0], 1});
        for(int i = 1; i< word.size(); i++)
        {
            if(word[i] == st.top().first && st.top().second <9)
            {
                st.top().second++;
                continue;
            }
            else
                st.push({word[i],1});
        }string result = "";
        while(!st.empty())
        {
            result+=st.top().first;
            result+=(st.top().second+'0');
            st.pop();
        }reverse(result.begin(), result.end());
        return result;
        
    }
};