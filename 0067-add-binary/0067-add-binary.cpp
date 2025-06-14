class Solution {
public:
    string addBinary(string a, string b) {

        int i  = a.size()-1;
        int j = b.size()-1;
        string ans = "";
        int carry = 0; 
        while(i>=0 && j>=0)
        {
            if(a[i] == '0')
            {
                if(b[j] == '0')
                {
                    if(carry == 1)
                    {
                        ans = "1" + ans; carry = 0; 
                    }
                    else
                    {
                        ans = "0"+ans;
                    }
                }
                else
                {
                    if(carry == 1)
                    {
                        ans = "0"+ans; 
                    }
                    else
                    {
                        ans = "1"+ans;
                    }
                }
            }
            else
            {
                if(b[j] == '0')
                {
                    if(carry == 1)
                    {
                        ans = "0" + ans; 
                    }
                    else
                    {
                        ans = "1"+ans;
                    }
                }
                else
                {
                    if(carry == 1)
                    {
                        ans = "1"+ans; 
                    }
                    else
                    {
                        ans = "0"+ans; carry = 1; 
                    }
                }
            }
            i--; j--;
        }
        while(i>=0)
        {
            if(carry ==1)
            {
                if(a[i]=='0')
                {
                    ans = "1"+ans; carry = 0; 
                }
                else
                {
                    ans = "0"+ans; 
                }
            }
            else
            {
                if(a[i] == '0')
                {
                    ans = "0"+ans; 
                }
                else
                {
                    ans = "1"+ans;
                }
            }
            i--;
        }
        while(j>=0)
        {
            if(carry ==1)
            {
                if(b[j]=='0')
                {
                    ans = "1"+ans; carry = 0; 
                }
                else
                {
                    ans = "0"+ans; 
                }
            }
            else
            {
                if(b[j] == '0')
                {
                    ans = "0"+ans; 
                }
                else
                {
                    ans = "1"+ans;
                }
            }
            j--;
        }
        if(carry == 1)
        {
            ans = "1"+ans;
        }
        return ans; 
        
    }
};