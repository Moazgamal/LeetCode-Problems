class Solution {
    vector<int> fn(string &p)
    {
        vector<int> longest(p.size(),0);
        for(int i=1,k=0; i<p.size(); i++)
        {
            while(k>0 && p[i] != p[k])
            {
                k= longest[k-1];
            }
            if(p[i] == p[k])
                longest[i]=++k;
            else
                longest[i]=k;
        }return longest;
    }
public:
    string longestPrefix(string s) {



        // Pie table

        vector<int> v = fn(s);
        if(v[v.size()-1] ==0)
            return "";
        return s.substr(0,v[v.size()-1]);

        
    }
};