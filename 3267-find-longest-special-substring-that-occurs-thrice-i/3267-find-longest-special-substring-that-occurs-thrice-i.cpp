class Solution {
public:
    int maximumLength(string s) {
        int ans = 0 ;
        vector<pair<int,int>> v(26,{0,0});
        for(int i = 0; i< s.size(); )
        {
            int idx = s[i] - 'a';
            int j = i+1; 
            while(j< s.size() && s[j] == s[i])
            {
                j++;
            }
            int cnt = j-i;
            int freq = v[idx].first;
            ans = max(ans, freq-2);
            if(cnt < freq && cnt == freq-1  )
            {
                ans = max(ans, freq-1);
            }
            else if(cnt > freq)
            {
                ans = max(ans, max(freq, cnt-2));
                cout<<ans<<"second"<<s[i]<<"\n";
                v[idx].first = cnt;
                v[idx].second = 1;
            }
            else if(cnt== freq)
            {
                if(++v[idx].second >= 3)
                    ans = max(ans, cnt);
                if(v[idx].second>=2)
                    ans = max(ans, cnt-1);
            }
            
            i = j;
            
            
        }return ans > 0 ? ans : -1;
        
    }
};