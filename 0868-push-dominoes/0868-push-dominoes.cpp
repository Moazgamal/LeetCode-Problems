class Solution {
    string fn(string &dom)
    {
        string ans = "";
        for(int i = 0; i< dom.size(); i++)
        {
            if(dom[i] == '.')
            {
                if(i-1 >= 0 && i+1 < dom.size())
                {
                    if(dom[i-1] == 'R' && dom[i+1] == 'L')
                    {
                        ans.push_back('.');
                    }
                    else if(dom[i-1] == 'R')
                    {
                        ans.push_back('R');
                    }
                    else if(dom[i+1] == 'L')
                    {
                        ans.push_back('L');
                    }
                    else
                    {
                        ans.push_back('.');
                    }
                }
                else if(i-1>=0)
                {
                    if(dom[i-1] == 'L')
                    {
                        ans.push_back('.');
                    }
                    else if(dom[i-1] == 'R')
                    {
                        ans.push_back('R');
                    }
                    else
                    {
                        ans.push_back('.');
                    }
                }
                else if(i+1 < dom.size())
                {
                    if(dom[i+1] == 'L')
                        ans.push_back('L');
                    else
                        ans.push_back('.');
                }
                else
                    ans.push_back('.');
            }
            else
                ans.push_back(dom[i]);
        }return ans; 
    }
public:
    string pushDominoes(string dominoes) {
        string ans = "";
       
       while(true)
       {
            string x = fn(dominoes);
            if(x == ans)
                return x;
            ans = x; 
            dominoes = x;
       }return ans; 
        
    }
};