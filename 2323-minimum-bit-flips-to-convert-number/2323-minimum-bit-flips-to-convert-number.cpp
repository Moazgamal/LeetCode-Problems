class Solution {
    string conv(int num)
    {
        string s = "";
        while(num > 0)
        {
            s.push_back((num%2)+'0');
            num /= 2;
        }
        reverse(s.begin(), s.end());
        return s; 
    }
public:
    int minBitFlips(int start, int goal) {
        string str1 = conv(start);
        string str2 = conv(goal);
        if(str1.size() > str2.size())
        {
            int diff = str1.size() - str2.size(); 
            string x (diff, '0');
            str2 = x + str2;
        }
        else if(str2.size() > str1.size())
        {
            int diff = str2.size() - str1.size(); 
            string x (diff, '0');
            str1 = x + str1;
        }
        int ans = 0; 
        for(int i = 0; i< str1.size(); i++)
        {
            if(str1[i] != str2[i])
                ans++;
        }
        return ans; 


        
    }
};