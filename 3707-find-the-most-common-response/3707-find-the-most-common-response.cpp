class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        unordered_map<string,int>mp;
        for(int i = 0; i< responses.size(); i++)
            {
                unordered_map<string,int>mp2;
                for(int j = 0; j< responses[i].size(); j++)
                    {
                        if(mp2.count(responses[i][j])==0)
                        {
                            mp[responses[i][j]]++;
                            mp2[responses[i][j]]++;
                        }
                    }
            }
        string ans ="";
        int maxi = 0; 
        for(auto x: mp)
            {
                if(x.second> maxi)
                {
                    ans = x.first;
                    maxi = x.second;
                }
                else if(x.second == maxi)
                {
                    if(ans == "")
                    {
                        ans = x.first;
                    }
                    else
                    {
                        ans = min(ans, x.first);
                    }
                }
                    
            }
        return ans;
        
    }
};