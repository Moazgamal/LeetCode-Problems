class Solution {
public:
    int maxProduct(int n) {

        int ans = 0; 
        string s = to_string(n);
        for(int i = 0; i< s.size(); i++)
            {
                for(int j = i+1; j< s.size(); j++)
                    {
                        ans = max(ans, (s[i]-'0')*(s[j]-'0'));
                    }
            }
        return ans;
        
    }
};