class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0; 
        int i = 0; 
        int j = 1;
        while(j<s.size() && s[j] == s[i])
            j++;
        int k = j;
        while(j<s.size())
        {
            k = j;
            while(k<s.size() && s[k] == s[j])
                k++;
            ans+= (min((j-i), (k-j)));
            i = j;
            j = k;
        }
        return ans;
    }
};