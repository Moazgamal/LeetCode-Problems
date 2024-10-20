class Solution {
public:
    vector<string> stringSequence(string target) {
        vector<string> result;
        string s  ="a";
         result.push_back(s);
        for(int i =0; i< target.size(); i++)
        {
            while(s[s.size()-1] != target[i])
            {
                s[s.size()-1]++;
                result.push_back(s);
            }
            s+="a";
            if(i != target.size()-1)
                result.push_back(s);
        }return result;
        
        
    }
};