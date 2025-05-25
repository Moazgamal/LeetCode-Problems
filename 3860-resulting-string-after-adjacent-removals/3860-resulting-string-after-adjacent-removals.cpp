class Solution {
public:
    string resultingString(string s) {

        stack<char> st;
        for(int i = 0; i< s.size(); i++)
        {
            if(st.empty())
            {
                st.push(s[i]); continue;
            }
            else if(abs((st.top()-'a')-(s[i]-'a')) == 1 || s[i] == 'a' && st.top()=='z' || s[i] == 'z' && st.top()=='a')
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        string ans ="";
        while(!st.empty())
        {
            ans.push_back(st.top()); st.pop();
        }
        reverse(ans.begin(), ans.end());return ans; 
        
    }
};