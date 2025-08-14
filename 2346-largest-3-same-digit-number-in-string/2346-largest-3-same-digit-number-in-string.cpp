class Solution {
public:
    string largestGoodInteger(string num) {
        string ans = "";
        int maxi = -1; 
        int charAns = -1; 
        for(int i = 0; i<= num.size()-3; i++)
        {
            int j = i+1; 
            while(j< num.size() && num[i] == num[j])
            {
                j++;
            }
            if(j-i>=3)
            {
                if((num[i]-'0') > charAns)
                {
                    maxi = j-i; ans = num.substr(i, 3);
                    charAns = num[i] -'0';
                }
            }
            i=j-1;
        }
        return ans; 
        

    }
};