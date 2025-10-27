class Solution {
public:
    string thousandSeparator(int n) {
        string str = to_string(n);
        if(str.size()<=3)
            return str; 
        string ans = ""; 
        for(int i =str.size()-3; i>=0; )
        {
           ans  = str.substr(i,3) + ans;
           if(i>0)
                ans = '.'+ans;
           i-=3;
        }
        // if(str.size()%3 == 0)
        //     return ans.substr(1, ans.size()-1); 
        int x = str.size() %3;

       return str.substr(0,x)+ans;
        
    }
};