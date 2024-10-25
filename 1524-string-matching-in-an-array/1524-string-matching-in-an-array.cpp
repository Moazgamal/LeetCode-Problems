class Solution {
    vector<int> fn(string &s)
    {
        vector<int> longestk(s.size(), 0);
        for(int i = 1, k=0; i< s.size(); i++)
        {
            while(k>0 && s[i] != s[k])
            {
                k = longestk[k-1];
            }
            if(s[i] == s[k])
            {
                longestk[i] = ++k;
            }
            else
                longestk[i] = k;
        }return longestk;
    }
    bool fn2(string &str, string &pat, vector<int>&longest)
    {
        int k = 0; 
        for(int i = 0; i< str.size(); i++)
        {
            while(k>0 && str[i] != pat[k])
            {
                k = longest[k-1];
            }
            if(str[i] == pat[k])
                k++;
            if(k==pat.size())
                return true;
        }
        
        return false;
    }
public:
    vector<string> stringMatching(vector<string>& words) {


       vector<string> result;
        for(int i = 0; i< words.size(); i++)
        {
            
            vector<int> v = fn(words[i]);

            for(int j= 0; j< words.size(); j++)
            {
                 if(j==i || words[i].size() > words[j].size())
                    continue;
                if(fn2(words[j], words[i],v))
                    {
                        result.push_back(words[i]);
                        break;
                    }
            }
        }return result;
        
    }
};