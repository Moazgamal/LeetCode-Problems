class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {

        int diff = 0; 
        unordered_map<int,int>mp1;
        unordered_map<int,int>mp2;
        for(int i = 0; i< s1.size(); i++)
        {
            mp1[s1[i]]++; mp2[s2[i]]++;
        }

        for(int i = 0; i< s1.size(); i++)
        {
            if(mp1[s1[i]] != mp2[s1[i]])
                return false;
            if(s1[i] != s2[i])
                diff++;
            if(diff > 2)
                return false;
        }
        return diff != 1;
        
    }
};