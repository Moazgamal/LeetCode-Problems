class Solution {
    string RLE(string n)
    {
        string ans = "";
        for(int i = 0; i< n.size();)
        {
            int j = i+1 ;
            while(j<n.size() && n[j]==n[i])
            {
                j++;
            }
            ans += to_string(j-i)+n[i];
            i=j;
        }
        return ans; 
    }
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        string ans = "1";
       for(int i = 2; i<= n ; i++)
       {
            ans = RLE(ans);
       }
       return ans; 

    }
};