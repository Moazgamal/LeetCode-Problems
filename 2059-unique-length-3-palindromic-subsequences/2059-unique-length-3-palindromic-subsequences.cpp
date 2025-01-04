class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<pair<int,int>>v(26,make_pair(INT_MAX,INT_MIN));
        unordered_set<int>st;
        for(int i = 0; i< s.size(); i++)
        {
            int idx = s[i]-'a';
            v[idx].first = min(v[idx].first,i);
            v[idx].second = max(v[idx].second,i);
            st.insert(v[idx].first);
            st.insert(v[idx].second);
        }
        vector<vector<int>>mp(s.size());
        vector<int>x(26,0);
        for(int i = 0; i< s.size(); i++)
        {
            int idx = s[i]-'a';
            x[idx]++;
            if(st.find(i) != st.end())
                mp[i]=x;
        }
        int ans  = 0; 
        for(int i =0; i< v.size(); i++)
        {
            int start = v[i].first;
            int end = v[i].second;
            if(start== end || start == INT_MAX || end== INT_MIN || end-start == 1)
                continue;
            for(int j = 0; j< 26; j++)
            {
                int f = mp[end][j];
                int y = mp[start][j];
                if(j == i)
                    f--;
                if(f-y > 0)
                    ans++;
            }
        }return ans;

    }
};