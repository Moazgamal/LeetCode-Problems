class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int ans = 0; 
        for(int i = 0; i< words.size()-1; i++)
        {
            for(int j = i+1; j< words.size(); j++)
            {

                if(words[j].size() < words[i].size())
                    continue;
                if(words[i] == words[j].substr(0, words[i].size()))
                {
                    int start = words[j].size() -words[i].size();
                    if(words[j].substr(start, words[i].size()) == words[i])
                        ans++;
                }
            }
        }return ans;
        
    }
};