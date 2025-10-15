class Solution {
public:
    int longestBalanced(string s) {
        vector<vector<int>>v(s.size(), vector<int>(26,0));
        vector<int>x(26,0);
        for(int i = 0; i< s.size(); i++)
        {
            x[s[i]-'a']++;
            v[i] = x;
        }
        int ans = 1;
        for(int j = s.size()-1; j>=1; j--)
        {
            int unified = -1;
            vector<int>v1 = v[j];
            for(int m = 0; m< v1.size(); m++)
            {
                if(v1[m] == 0)
                    continue;
                if(unified == -1)
                    unified = v1[m];
                else
                {
                    if(unified != v1[m])
                    {
                        unified = -1; break;
                    } 
                    unified = v1[m];
                }
            }
            if(unified!=-1)
            {
                ans = max(ans, j+1);
                break;
            }
            unified = -1; 
            for(int i = 1; i<j; i++)
            {
                vector<int>v2 = v[i-1];
                for(int u = 0; u< 26; u++)
                {
                    if(v1[u] == 0 && v2[u] == 0)
                        continue;
                    if(v1[u] - v2[u] == 0)
                        continue;
                    if(unified == -1 )
                    {
                       unified = v1[u]-v2[u];
                    }
                    else
                    {
                        if(v1[u]-v2[u] != unified)
                        {
                            unified = -1; break;
                        }
                    }
                }
                if(unified != -1)
                {
                    ans = max(ans, j-i+1);
                }
                unified = -1; 
            }
        }
        return ans; 
        
    }
};