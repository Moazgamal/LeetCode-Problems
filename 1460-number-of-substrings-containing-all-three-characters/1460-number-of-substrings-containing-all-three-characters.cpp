class Solution {
public:
    int numberOfSubstrings(string s) {
        int j = 0; 
        unordered_map<char,int> mp; 
        int ans = 0; 
        for(int i  =0; j< s.size(); )
        {
            mp[s[j]]++;
            while(mp.size() ==3)
            {
                ans+= s.size()-j;
                if(--mp[s[i]] ==0)
                    mp.erase(s[i]); 
                i++; 
            }
            j++; 
        }
        return ans; 
        
    }
};