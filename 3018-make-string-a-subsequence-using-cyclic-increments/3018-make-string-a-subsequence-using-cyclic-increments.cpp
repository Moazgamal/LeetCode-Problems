class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        int j = 0; 
        for(int i =0; i<str2.size(); i++)
        {
            bool match = false;
            char c = str2[i];
            for(; j< str1.size(); j++)
            {
                char c1 = str1[j];
                char c2 = (((c1-'a')+1)%26)+'a';
                if(c1 == c|| c2 == c )
                {
                    j++; match = true; break;
                }
            }
            if(!match)
                return false;
            
        }return true;
        
    }
};