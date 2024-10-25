class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans(queries.size(),false);
        cout<<ans[0]<<" \n";
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        
        for(int i = 0; i< pattern.size(); i++)
        {
            if(isupper(pattern[i]))
            {
                mp1[pattern[i]]++;
            }
            else
                mp2[pattern[i]]++;
        }
        for(int i = 0; i< queries.size(); i++)
        {
            int k = 0;\
            bool indi = false;
            string x= queries[i];
            for(int j = 0; j< x.size(); j++)
            {
                if(isupper(x[j]) && k== pattern.size())
                {
                    ans[i] = false;
                    indi = true;
                    break;
                }
                else if(isupper(x[j]))
                {
                    if(mp1.count(x[j])==0 || pattern[k] != x[j])
                    {
                        ans[i]=false;
                        break;
                    }
                    
                    
                }
                if(k<pattern.size() && x[j] == pattern[k])
                {
                    k++;
                }
            }
            if(indi == false && k==pattern.size())
                ans[i]=true;
        }
        return ans;
        
    }
};