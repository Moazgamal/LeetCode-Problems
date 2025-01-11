class Solution {
public:
    bool canConstruct(string s, int k) {

        unordered_map<char,int>mp;
        for(auto c : s)
            mp[c]++;
        int oddFreqs = 0;  int evenFreqs = 0; 
        for(auto freq: mp)
        {
            if(freq.second %2 ==0)
                evenFreqs++;
            else
                oddFreqs++;
        }
        if(k< oddFreqs || k> s.size())
            return false;
        return true;

        
    }
};