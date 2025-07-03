class Solution {
public:
    char kthCharacter(int k) {


        string x = "a";
        if(k<=x.size())
            return x[k-1];
        
        while( k>(int)x.size())
        {
            int sz = (int)x.size();
            int j = 0; 
            while(j<sz)
            {
                if(x[j]=='z')
                {
                    x.push_back('a');
                    continue;
                }
                int m = x[j]-'a';
                m++;
                
                x.push_back(m+'a');
                j++;
            }
        }
        return x[k-1];
        
    }
};