class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        unordered_map<string, int> mp;
        vector<string> result;
        for(int i = 0;i < folder.size(); i++)
        {
            string str ="";
            for(int j = 0; j< folder[i].size(); j++)
            {
                if(folder[i][j]=='/')
                    continue;
                while(j<folder[i].size() && folder[i][j] != '/')
                {
                    str.push_back(folder[i][j]); j++;
                }
                str.push_back('/');
                
            }
            mp[str]++;
        }
        for(int i = 0; i< folder.size(); i++)
        {
            string str ="";
            string str2 = "";
            bool x = true;
            for(int j = 0; j< folder[i].size(); j++)
            {
                if(folder[i][j]=='/')
                    continue;
                while(j<folder[i].size() && folder[i][j] != '/')
                {
                    str.push_back(folder[i][j]);
                     j++;
                }
                str.push_back('/');
                if(mp.count(str)!=0 )
                {
                    x=false; 
                    str2 = str;
                    break;
                }
            }
            str2.pop_back();
            if(x)
                result.push_back(folder[i]);
            else
            {
                if(str2 == folder[i].substr(1,folder[i].size()))
                    result.push_back(folder[i]);
            }
        }
        return result;
        
    }
};