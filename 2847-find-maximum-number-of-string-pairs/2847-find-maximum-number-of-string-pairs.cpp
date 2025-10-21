class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_map<int,int>mp;
        int ans = 0; 
        for(int i = 0; i< words.size(); i++)
        {
            if(mp.count(i) !=0)
                continue;
            for(int j = i+1; j< words.size(); j++)
            {
                reverse(words[j].begin(), words[j].end());
                if(words[i] == words[j])
                {
                    mp[j]++; ans++; break;
                }
                else
                {
                    reverse(words[j].begin(), words[j].end());
                }
                reverse(words[i].begin(), words[i].end());
                if(words[i] == words[j])
                {
                    mp[j]++; ans++; break;
                }
                else
                {
                    reverse(words[i].begin(), words[i].end());
                }
            }
        }
        return ans; 
        
    }
};