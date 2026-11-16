class Solution {
public:
    int uniqueLetterString(string s) {

        int ans = 0; 
        unordered_map<char,vector<int>>mp;
        unordered_map<char,int> I;
        int unique = 0; 
        for(int i = 0; i< s.size(); i++)
        {
            if(mp.count(s[i]) ==0)
                unique++;
            else if(mp[s[i]].size() == 1)
                unique--;

            mp[s[i]].push_back(i);
            ans += unique;
        }
        int firstAns = ans;
        // cout<<firstAns<<" \n";
        for(int i =  0; i< s.size(); i++)
        {
            int i1 = s.size();
            int i2 = -1;
            I[s[i]]++;
            if(I[s[i]] != mp[s[i]].size())
            {
                i1 = mp[s[i]][I[s[i]]]; i2 = i1;
                if(I[s[i]]+1<mp[s[i]].size())
                    i2 = mp[s[i]][I[s[i]]+1];
            }
            
            firstAns -= (i1-i);
            if(i2 != -1)
            {
                if(i1 == i2)
                    firstAns += (s.size()-i1);
                else
                    firstAns += (i2-i1);
            }
            // cout<<firstAns<<" \n";
            ans += firstAns;
        }   
        return ans; 
        
    }
};