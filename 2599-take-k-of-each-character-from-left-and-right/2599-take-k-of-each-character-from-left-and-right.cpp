class Solution {
    
public:
    int takeCharacters(string s, int k) {
        if(k==0)
            return 0; 
        if(s.size()<3)
            return -1;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;
        int j = s.size()-1;
        int ans = INT_MAX;
        for(int i= 0; i< s.size(); i++)
        {
            mp1[s[i]]++; mp2[s[j-i]]++;
        }
        if(mp1['a']<k || mp1['b']<k || mp1['c'] <k)
            return -1;
        int i =0; j =1;
        while(i<s.size())
        {
            while(j<s.size() && mp1[s[j]]>k)
            {
                mp1[s[j]]--; j++;
                ans = min(ans, i+1+(int)s.size()-j);
            }
            if(j==s.size())
                break;
            char c = s[j]; mp1[s[j]]--; j++;
            while(mp1[c] <k)
            {
                i++;
                mp1[s[i]]++; 
            }
            ans = min(ans, i+1+(int)s.size()-j);
        }
         i =s.size()-1;  j =s.size()-2;
        while(i>=0)
        {
            while(j>=0 && mp2[s[j]]>k)
            {
                mp2[s[j]]--; j--;
                ans = min(ans, j+1+(int)s.size()-i);
            }
            if(j<0)
                break;
            char c = s[j]; mp2[s[j]]--; j--;
            while(mp2[c] <k)
            {
                i--;
                mp2[s[i]]++; 
            }
            ans = min(ans, j+1+(int)s.size()-i);
        }
        return ans;

    }
};