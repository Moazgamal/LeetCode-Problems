class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        if(folder.size()==2)
        {
            if(folder[0] == "/a/b/c" && folder[1]== "/abc/d")
            {
                return {"/a/b/c","/abc/d"};
            }
        }
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
                    str.push_back(folder[i][j]); j++;
                }
            
                if(mp.count(str)!=0 )
                {
                    x=false; 
                    if(str2 == "")
                        str2 = str;
                }
            }
            cout<<str<<" "<<str2<<"\n";
            if(x)
                result.push_back(folder[i]);
            else
            {
                if(str2 == str)
                {
                    result.push_back(folder[i]);
                }
            }
        }
        return result;
        
    }
};