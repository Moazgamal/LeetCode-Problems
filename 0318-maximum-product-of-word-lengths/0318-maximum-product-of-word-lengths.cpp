class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<vector<int>>v(words.size(), vector<int>(26,0));
        for(int i = 0; i< words.size(); i++)
        {
            for(int j = 0; j< words[i].size(); j++)
            {
                v[i][words[i][j]-'a']++;
            }
        }
        int ans = 0; 
        for(int i = 0; i< words.size(); i++)
        {
            vector<int>v1 = v[i];
            for(int j = i+1; j< words.size(); j++)
            {
                vector<int>v2 = v[j];
                bool x = true; 
                for(int k = 0; k< 26; k++)
                {
                    if(v1[k] >0 && v2[k]>0)
                    {
                        x=false; break;
                    }
                }
                if(x)
                {
                    ans = max(ans, (int)words[i].size()*(int)words[j].size());
                }
            }
        }return ans;
        
    }
};