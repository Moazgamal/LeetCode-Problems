class Solution {
public:
    int minLength(string s) {

        char prev = '-';
        int cnt = 1;
        stack<char>st;
        st.push(s[0]);
        for(int i=1; i< s.size(); i++)
        {
            
            
            if(s[i]=='B')
            {
                if(!st.empty()&& st.top()=='A')
                {
                    st.pop();
                    cnt-=2;
                }
                else
                    st.push(s[i]);
            }
            else if(s[i]=='D')
            {
                 if(!st.empty()&& st.top()=='C')
                {
                    st.pop();
                    cnt-=2;
                }
                else
                    st.push(s[i]);
            }
            else
                st.push(s[i]);

        }
        return st.size();
        
    }
};