class Solution {
public:
    int maximumGain(string s, int x, int y) {
        stack<char>st;
        int ans = 0; 
        string str ="";
        if(x>=y)
        {
            int i = 0; 
            while(i< s.size())
            {
                if(st.empty())
                {
                    st.push(s[i]); i++;
                }
                else
                {
                    if(s[i] == 'b')
                    {
                        if(st.top()=='a')
                        {
                            st.pop(); ans += x;
                        }
                        else
                            st.push(s[i]);
                    }
                    else
                        st.push(s[i]);
                    i++;
                }
            }
            
            while(!st.empty())
            {
                str.push_back(st.top()); st.pop();
            }
            reverse(str.begin(), str.end());

            i=0;
            while(i< str.size())
            {
                if(st.empty())
                {
                    st.push(str[i]);
                    i++;
                }
                else
                {
                    if(str[i] == 'a' && st.top()== 'b')
                    {
                        st.pop(); ans += y;
                    }
                    else
                    {
                        st.push(str[i]);
                    }
                    i++;
                }
            }


        }
        else
        {
            int i = 0; 
            while(i< s.size())
            {
                if(st.empty())
                {
                    st.push(s[i]); i++;
                }
                else
                {
                    if(s[i] == 'a')
                    {
                        if(st.top()=='b')
                        {
                            st.pop(); ans += y;
                        }
                        else
                            st.push(s[i]);
                    }
                    else
                        st.push(s[i]);

                    i++;
                }
            }

           while(!st.empty())
            {
                str.push_back(st.top()); st.pop();
            }
            reverse(str.begin(), str.end());
            i=0;
            while(i< str.size())
            {
                if(st.empty())
                {
                    st.push(str[i]);
                    i++;
                }
                else
                {
                    if(str[i] == 'b' && st.top()== 'a')
                    {
                        st.pop(); ans += x;
                    }
                    else
                    {
                        st.push(str[i]);
                    }
                    i++;
                }
            }
        }
        return ans; 
        
    }
};