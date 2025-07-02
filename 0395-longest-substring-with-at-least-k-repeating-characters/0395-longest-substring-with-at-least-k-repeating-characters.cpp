class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0; 
        unordered_map<char,int>mp;
        for(auto x: s)
            mp[x]++;
        int len = 0;
        
        for(int i = 0; i< s.size(); )
        {
            if(mp[s[i]]<k)
            {
                i++; continue;
            }
            else
            {
                int j = i; 
                vector<int>cur(26,0);
                vector<int>lastidx(26,-1);
                while(i<s.size() && mp[s[i]]>=k)
                {
                    cur[s[i]-'a']++;
                    lastidx[s[i]-'a']= i;
                    bool u = true;
                    int lastinvalid = -1;
                    for(int h = 0; h< 26 ; h++)
                    {
                        if(cur[h] ==0)
                            continue;
                        if(cur[h] > 0 && cur[h] >=k)
                        {
                            continue;
                        }
                        else
                        {
                            u = false;
                            lastinvalid = h;
                        }
                    }
                    if(u)
                    {
                        ans = max(ans,(i-j)+1);
                    }
                    if(lastinvalid !=-1)
                    {
                        bool t = true;
                        vector<int>r (26,0);
                        for(int e = lastidx[lastinvalid]+1; e<=i; e++)
                        {
                            r[s[e]-'a']++;
                        }
                        for(int h = 0; h< 26 ; h++)
                        {
                            if(r[h] ==0)
                                continue;
                            if(r[h] > 0 && r[h] >=k)
                            {
                                continue;
                            }
                            else
                            {
                                t = false;
                                break;
                            }
                        }
                        if(t)
                            ans = max(ans, i-lastidx[lastinvalid]);
                    }
                    i++;
                }
                while(j<i-1)
                    {
                        cur[s[j]-'a']--;
                        bool u = true;
                        for(int m = 0; m < 26; m++)
                        {
                           
                            if(cur[m] ==0)
                                continue;
                            if(cur[m] > 0 && cur[m] >=k)
                            {
                                continue;
                            }
                            else
                            {
                                u = false;
                                break;
                            }
                        }
                        if(u)
                        {
                            cout<<"fffffffffffffff\n";
                            cout<<i<<" "<<j<<"\n";
                            ans = max(ans, i-j-1);
                            break;
                        }
                        j++;
                    }
                
            }
        }
        return ans; 
        
    }
};