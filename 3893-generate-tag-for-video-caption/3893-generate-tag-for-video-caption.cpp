#include <cctype>
class Solution {
public:
    string generateTag(string caption) {

        string ans = "";
        
        for(int i = 0; i< caption.size(); i++)
            {
                if(i==0)
                {
                    ans.push_back('#');
                    if(caption[0] != ' ')
                        ans.push_back(tolower(caption[0]));
                    else
                    {
                        while(i<caption.size() && caption[i] == ' ')
                            {
                                i++;
                            }
                        if(i<caption.size())
                        {
                            ans.push_back(tolower(caption[i]));
                        }
                    }
                    
                    continue;
                }
                else if(caption[i] == ' ')
                    continue;
                else if(i-1>=0 && caption[i-1] == ' ')
                {
                    ans.push_back(toupper(caption[i]));
                }
                else
                {
                    ans.push_back(tolower(caption[i]));
                }
            }
        if(ans.size() >100)
            return ans.substr(0,100);
        return ans; 
        
    }
};