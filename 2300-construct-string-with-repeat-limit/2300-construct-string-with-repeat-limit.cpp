class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {

        vector<int> v(26,0);
        for(int i= 0; i< s.size(); i++)
        {
            int idx = s[i]-'a';
            v[idx]++;
        }
        stack<pair<char,int>>st;
        for(int i = 0; i< v.size(); i++)
        {
            if(v[i] >0)
            {
                char c = 'a'+i;
                st.push({c,v[i]});
            }
        }
        string ans = "";
        while(!st.empty())
        {
            int x = repeatLimit;
            auto cur = st.top();
            st.pop();
            if(cur.second ==0)
                continue;
            if(cur.second > x)
            {
                ans += string(x,cur.first);
                cur.second -= repeatLimit;
                if(st.empty())
                    return ans;
                auto cur2 = st.top();
                ans.push_back(cur2.first);
                if(--st.top().second == 0)
                    st.pop();
                st.push(cur);
            }
            else if(cur.second == x)
                ans += string(x, cur.first);
            else
                ans += string(cur.second, cur.first);
        }
        return ans;
        
    }
};