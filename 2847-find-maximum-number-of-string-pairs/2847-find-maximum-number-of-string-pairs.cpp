class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        vector<bool>mp(words.size(), false);
        int ans = 0; 
        int i = 0; int sz = (int)words.size();
        while(i< sz)
        {
            if(mp[i] == true)
            {
                i++;
                continue;
            }
            int j = i+1;
            while(j< sz)
            {
                if(mp[j] == true)
                {
                    j++; continue;
                }
                reverse(words[j].begin(), words[j].end());
                if(words[i] == words[j])
                {
                    mp[j]=true; ans++; break;
                }
                else
                {
                    reverse(words[j].begin(), words[j].end());
                }
                reverse(words[i].begin(), words[i].end());
                if(words[i] == words[j])
                {
                    mp[j]=true; ans++; break;
                }
                else
                {
                    reverse(words[i].begin(), words[i].end());
                }
                j++;
            }
            i++;
        }
        return ans; 
        
    }
};