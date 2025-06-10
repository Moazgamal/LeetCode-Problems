class Solution {
public:
    int maxDifference(string s) {

        int odd = 0; 
        int even = INT_MAX;
        vector<int>v(26,0);
        for(int i = 0; i< s.size(); i++)
        {
            v[s[i]-'a']++;
        }
        for(int i = 0; i< v.size(); i++)
        {
            if(v[i]%2 ==0 && v[i] !=0)
                even=min(even, v[i]);
            else
                odd=max(odd, v[i]);
        }
        return odd-even;
        
    }
};