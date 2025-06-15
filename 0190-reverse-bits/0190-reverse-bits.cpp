class Solution {
    string BS(uint32_t n)
    {
        int rem = 0; 
        string str = "";
        while(n>0)
        {
            str.push_back((n%2)+'0');
            n = n/2;
        }
        reverse(str.begin(), str.end());
        return str; 
    }
    int fn(string str)
    {
        long long x = 1;
        int ans = 0; 
        for(int i = str.size()-1; i>=0; i--)
        {
            ans += (x*(str[i]-'0'));
            x*=2;
        }
        return ans; 
    }
public:
    uint32_t reverseBits(uint32_t n) {
        string str  = BS(n);
        
        reverse(str.begin(), str.end());
        int sz = 0; 
        if(str.size()<32)
        {
            sz = 32 - str.size(); 
        }
        while(sz-- >0 )
        {
            str.push_back('0');
        }
        cout<<str<<"\n";
        return fn(str);
        
    }
};