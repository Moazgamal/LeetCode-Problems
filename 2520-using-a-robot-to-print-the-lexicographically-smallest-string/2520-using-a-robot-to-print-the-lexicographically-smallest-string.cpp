class Solution {
public:
    string robotWithString(string s) {

        stack<int>st;
        vector<int> ind(s.size(),-1);
        for(int i= 0; i< s.size(); i++)
        {
            if(st.empty())
            {
                st.push(i);
                continue;
            }
            while(!st.empty() && s[i]< s[st.top()])
            {
                ind[st.top()]= i;
                st.pop();
            }
            st.push(i); 
        }

        string ans = "";
        stack<char> t;
        for(int i = 0; i< s.size(); i++)
        {
            int j = i;
            int _j = i ;
            while(j< s.size() && j!=-1)
            {
                _j = j; 
                j = ind[j];
            }
            if(t.empty())
            {
                ans.push_back(s[_j]);
                while(i<_j)
                {
                    t.push(s[i]);
                    i++;
                }
            }
            else
            {
                while(!t.empty() && s[_j]>= t.top())
                {
                    ans.push_back(t.top());
                    t.pop();
                }
                ans.push_back(s[_j]);
                while(i<_j)
                {
                    t.push(s[i]);
                    i++;
                }
            }
        }
        while(!t.empty())
        {
            ans.push_back(t.top());
            t.pop();
        }
        return ans;
        
        
        
    }
};