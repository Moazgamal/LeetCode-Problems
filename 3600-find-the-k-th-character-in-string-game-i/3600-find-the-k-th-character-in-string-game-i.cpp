class Solution {
public:
    char kthCharacter(int k) {


        string x = "a";
        if(k<=x.size())
            return x[k-1];
        for(int i=0; k>x.size(); i++)
        {
            int sz = x.size();
            for(int j=0; j<sz; j++)
            {
                if(x[j]=='z')
                {
                    x.push_back('a');
                    continue;
                }
                int m = x[j]-'a';
                m++;
                
                x.push_back(m+'a');
                cout<<m+'a'<<"\n";
            }
        }
        return x[k-1];
        
    }
};