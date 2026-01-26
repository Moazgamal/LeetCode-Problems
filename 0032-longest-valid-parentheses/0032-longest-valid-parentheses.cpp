class Solution {
public:
    int longestValidParentheses(string s) {
        int cnt = 0; 
        int ans = 0; 
        stack<int>st;
        map<int,int>mp;
        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] == '(')
                st.push(i);
            else
            {
                if(st.empty())
                    continue;
                auto idx = st.top();
                st.pop();
                mp[idx] = i; 
            }
        }
        int end = -1; 
        for(auto x: mp)
        {
            int curStart = x.first;
            int curEnd = x.second;
            if(end == -1)
                end = curEnd;
            else if(curStart < end)
                continue;
            int len = curEnd-curStart+1;
            ans = max(ans, curEnd- curStart+1);
            while(mp.count(curEnd+1) >0)
            {
                end = mp[curEnd+1];
                len += (mp[curEnd+1] - (curEnd+1) +1);
                ans = max(ans, len);
                curEnd = mp[curEnd+1];
            }
        }
        // i will optimize it later
        // by using vector and make it o(n) time comp
        return ans; 
    }
};