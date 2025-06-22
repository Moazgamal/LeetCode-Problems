class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string>ans;
        int i = 0; 
        while(i < s.size())
        {
            int j = i+k;
            string x = "";
            if(j>= s.size())
            {
                while(i<s.size())
                {
                    x.push_back(s[i]); i++;
                }
                while(i<j)
                {
                    x.push_back(fill);
                    i++;
                }
            }
            else
            {
                while(i<j)
                {
                    x.push_back(s[i]);
                    i++;
                }
            }
            ans.push_back(x);
        }return ans;
        
    }
};