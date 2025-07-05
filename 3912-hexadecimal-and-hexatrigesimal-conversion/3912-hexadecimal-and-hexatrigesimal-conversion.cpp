    #include <cctype> // for toupper
class Solution {
    string he(int number)
    {
        unordered_map<int,char>mp;
        mp[10]='A'; mp[11] = 'B';
        mp[12]= 'C'; mp[13]= 'D';
        mp[14]= 'E'; mp[15]= 'F';
        string str = "";
        while(number>0)
        {   
            int rem = number%16;
            if(rem>9)
            {
                str.push_back(mp[rem]);
            }
            else
            {
                str.push_back((rem+'0'));
            }
            number /= 16;
        }
        reverse(str.begin(), str.end());
        return str;
    }
    string h(int number)
    {
        unordered_map<int,char>mp;
        int j = 0; 
        for(int i = 10; i< 36; i++,j++)
        {
            mp[i] = toupper((j+'a'));
        }
        string str = "";
        while(number>0)
        {   
            int rem = number%36;
            if(rem>9)
            {
                str.push_back(mp[rem]);
            }
            else
            {
                str.push_back((rem+'0'));
            }
            number /= 36;
        }
        reverse(str.begin(), str.end());
        return str;
    }
public:
    string concatHex36(int n) {

        string s1 = he(n*n);
        string s2 = h(n*n*n);
        return s1+s2;
        
    }
};