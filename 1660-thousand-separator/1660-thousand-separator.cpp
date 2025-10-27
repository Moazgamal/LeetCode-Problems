class Solution {
public:
    string thousandSeparator(int n) {
        string str = to_string(n);
        if(str.size()<=3)
            return str; 
        string ans = ""; 
        int rem = str.size()%3;
        ans = str.substr(0,rem);
        if(rem >0)
            ans.push_back('.');
        int i = rem;
        while(i<str.size())
        {
            ans += (str.substr(i,3)); ans.push_back('.'); i+=3;
        }ans.pop_back(); return ans; 
        
    }
};