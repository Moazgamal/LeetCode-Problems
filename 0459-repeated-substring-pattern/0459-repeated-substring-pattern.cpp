class Solution {
public:
    bool repeatedSubstringPattern(string s) {


        vector<int> v(s.size(),0);
        for(int i =1,k=0; i< s.size(); i++)
        {
            while(k>0 && s[i] != s[k])
            {
                k= v[k-1];
            }
            if(s[k] == s[i])
                v[i] = ++k;
            else
                v[i] = k;
        }
        int maxi = v[v.size()-1];
        if(maxi ==0)
            return false;
        int divider = s.size()-maxi;
        if(maxi % divider !=0)
            return false;
        return true;
        
    }
};