class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> mp(26);
        unordered_set<int> st;
        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] != '*')
            {
                mp[s[i]-'a'].push_back(i); 
            }
            else
            {
                if(mp.size() ==0)
                    continue;
                bool f = true; 
                for(int x= 0; x< mp.size(); x++)
                {
                    if(f && mp[x].size()>0)
                    {
                        st.insert(mp[x][mp[x].size()-1]);
                        mp[x].pop_back();
                        break;
                    }
                }
            }
        }
            string ans = "";
            for(int i = 0; i< s.size(); i++)
            {
                
                    if(s[i] != '*' && st.find(i) == st.end())
                    {
                        ans.push_back(s[i]); 
                    }
            }
            return ans; 
            
        
    }
};