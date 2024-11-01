class Solution {
public:
    string makeFancyString(string s) {
        stack<pair<char,int>>st;
        st.push({s[0],1});
        for(int i = 1; i< s.size(); i++)
        {
            if(s[i] == st.top().first)
            {
                if(st.top().second+1 == 3)
                    continue;
                else
                    st.top().second++;
            }
            else
                st.push({s[i],1});
        }
        s.clear();
        while(!st.empty())
        {
            while(st.top().second--)
            {
                s+=st.top().first;
            }st.pop();
        }reverse(s.begin(), s.end());return s;
        
    }
};