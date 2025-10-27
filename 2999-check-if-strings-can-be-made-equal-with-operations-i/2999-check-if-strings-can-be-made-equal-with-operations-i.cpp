class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<int>v1(26,0);
        vector<int>v2(26,0);
        int i = 0;
        while(i<s1.size())
        {
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;
            i++;
        }
        i = 0; 
        while(i<v1.size())
        {
            if(v1[i]!=v2[i])
                return false; 
            i++;
        }
        vector<int>v3(26,0);
        vector<int>v4(26,0);
        i = s1.size()-1;
        v3[s1[i]-'a']++; v3[s1[i-2]-'a']++;
        v4[s2[i]-'a']++; v4[s2[i-2]-'a']++;
        if(v3[s1[i]-'a'] != v4[s1[i]-'a'] || v3[s1[i-2]-'a'] != v4[s1[i-2]-'a'])
            return false;
        i = i-1;  
        vector<int>v5(26,0);
        vector<int>v6(26,0);
        v5[s1[i]-'a']++; v5[s1[i-2]-'a']++;
        v6[s2[i]-'a']++; v6[s2[i-2]-'a']++;
        if(v5[s1[i]-'a'] != v6[s1[i]-'a'] || v5[s1[i-2]-'a'] != v6[s1[i-2]-'a'])
            return false;
        return true; 
    }
};