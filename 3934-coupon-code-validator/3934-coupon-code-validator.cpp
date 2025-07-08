class Solution {
    bool isvalid(string &s)
    {
        for(int i = 0; i< s.size(); i++)
        {
            if(isalnum(s[i]) || s[i] == '_')
                continue;
            return false;
        }
        return true;
    }
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {

        vector<string>answer;
        map<string,vector<string>>mp;
        for(int i = 0; i< code.size(); i++)
        {
            if(code[i] == "")
                continue;
            if(businessLine[i] == "electronics"|| 
            businessLine[i] == "grocery"||
            businessLine[i] == "pharmacy"||
            businessLine[i]=="restaurant")
            {
                if(isActive[i] == true)
                {
                    if(isvalid(code[i]))
                    {
                        mp[businessLine[i]].push_back(code[i]);
                    }
                }
            }
        }
        for(auto &x: mp)
        {
            sort(x.second.begin(), x.second.end());
            for(int i= 0; i< x.second.size(); i++)
            {
                answer.push_back(x.second[i]);
            }
        }return answer;
        
        
    }
};