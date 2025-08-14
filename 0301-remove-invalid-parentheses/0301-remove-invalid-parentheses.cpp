class Solution {
    bool check(string &str)
    {
        stack<char>st;
        for(int i = 0; i< str.size() ; i++)
        {
            
            if(str[i] == '(')
            {
                st.push(str[i]); continue;
            }
            else if(str[i] == ')')
            {
                if(st.empty())
                    return false;
                st.pop();
                continue;
            }
            
        }
        return st.empty();

    }
    void fn(int idx, string &s, string &str, vector<vector<string>>&mp, unordered_map<string, bool>&mp2, int noc, int noo)
    {
        if(noc > noo)
            return ; 
        
        if(idx>=s.size())
        {
            if(mp2.count(str) !=0)
                return ;
            else
                mp2[str]= true;
            if(check(str))
            {
                mp[(int)str.size()].push_back(str);
            }
            return ; 
        }
        if(s[idx] == '(')
        {
            noo++;
        }
        else if(s[idx] == ')')
            noc++;
        str.push_back(s[idx]);
        
        fn(idx+1, s, str, mp,mp2,noc, noo);
        str.pop_back();
        if(s[idx] == '(')
        {
            noo--;
        }
        else if(s[idx] == ')')
            noc--;
        fn(idx+1, s, str, mp,mp2, noc, noo);
    }
public:
    vector<string> removeInvalidParentheses(string s) {

        // let's go dp
        if(check(s))
            return {s};
        string u = ""; int num1 =0; int num2 = 0; 
        for(int i = 0; i< s.size(); i++)
        {
            if(s[i] == '(')
                num1++;
            else if(s[i] == ')')
                num2++;
            else
                u.push_back(s[i]);
        }
        if(num1 == 0 && num2>0 || num2==0 && num1>0)
            return {u}; 
        string acc = "";
        int noc  = 0; int noo=0;
        unordered_map<string,bool>mp2;
        vector<vector<string>> mp(26);
        fn(0,s, acc, mp,mp2, noc, noo);
        vector<string>ans;
        for(int i = mp.size()-1; i>=0; i--)
        {
            if(mp[i].size()>0)
            {
                for(int j = 0; j< mp[i].size(); j++)
                {
                    ans.push_back(mp[i][j]);
                }
                break;
            }
        }
        if(ans.size()==0)
            return {""};
        return ans;
        
    }
};