class Solution {
public:
    vector<string> partitionString(string s) {
        unordered_map<string,bool>mp;
        vector<string>v;
        for(int i = 0; i< s.size(); i++)
            {
                string str ="";
                str.push_back(s[i]);
                while(i<s.size() && mp.count(str) !=0)
                    {
                        i++;
                        if(i<s.size())
                            str.push_back(s[i]);
                    } 
                if(mp.count(str)==0)
                    v.push_back(str);
                mp[str]= true;
            }
        return v; 
        
    }
};