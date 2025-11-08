class Solution {
    string mul(int num1, string &num2)
    {
        string ans = "";
        int carry = 0; 
        int i = num2.size()-1; 
        while(i>=0)
        {
            string cur = to_string(((num2[i]-'0')*num1)+carry);
            ans.push_back(cur[cur.size()-1]);
            if(cur.size()>1)
            {
                carry = stoi(cur.substr(0,cur.size()-1));
            }
            else
                carry = 0; 
            i--;
        }
        if(carry>0)
        {
            string str = to_string(carry);
            reverse(str.begin(), str.end());
            ans += str;
        }
        reverse(ans.begin(), ans.end());
        return ans; 
    }
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
    string multiply(string num1, string num2) {
        if(num1[0] == '0' || num2[0] == '0')
            return "0";
        string ans = "";
        int cnt= 0; 
        for(int i = num1.size()-1; i>=0; i--, cnt++)
        {
            string s = mul(num1[i]-'0', num2);
            if(ans.size() == 0)
                ans = s;
            else
            {
                int j = cnt;
                while(j-- >0)
                    s.push_back('0');
                ans = sum(ans, s);
            }
        }
        return ans; 
    }
};