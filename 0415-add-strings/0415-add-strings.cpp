class Solution {
    string sum(string &ans, string &s)
    {
        string res = "";
        int carry = 0; 
        int j = s.size()-1;
        int i = ans.size()-1;
        while(i>=0 && j>=0)
        {
            string x = to_string((s[j]-'0') + (ans[i]-'0')+carry);
            if(x.size()>1)
            {
                carry = stoi(x.substr(0,x.size()-1));
            }
            else
                carry = 0; 

            res.push_back(x[x.size()-1]);
            i--; j--;
        }
        if(i < 0 && j <0)
        {
            if(carry>0)
            {
                string str = to_string(carry);
                reverse(str.begin(), str.end());
                res += str;
            }
            reverse(res.begin(), res.end());
            return res; 
        }
        else if(i>=0)
        {
            while(i>=0)
            {
                string x = to_string((ans[i]-'0')+carry);
                if(x.size()>1)
                {
                    carry = stoi(x.substr(0,x.size()-1));
                }
                else
                    carry = 0; 

                res.push_back(x[x.size()-1]);
                i--;
            }
            if(carry>0)
            {
                string str = to_string(carry);
                reverse(str.begin(), str.end());
                res += str;
            }
        }
        else
        {
            while(j>=0)
            {
                string x = to_string((s[j]-'0')+carry);
                if(x.size()>1)
                {
                    carry = stoi(x.substr(0,x.size()-1));
                }
                else
                    carry = 0; 

                res.push_back(x[x.size()-1]);
                j--;
            }
            if(carry>0)
            {
                string str = to_string(carry);
                reverse(str.begin(), str.end());
                res += str;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
public:
    string addStrings(string num1, string num2) {
        while(num1.size() < num2.size())
            num1="0"+num1;

        while(num2.size() < num1.size())
            num2="0"+num2;
        
        return sum(num1, num2);
        
    }
};