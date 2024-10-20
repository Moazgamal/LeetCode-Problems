class Solution {
public:
    bool parseBoolExpr(string expression) {

        stack<char>st1;
        stack<char>st2;
        for(int i = 0; i< expression.size() ; i++)
        {
            if(expression[i] == ',')
                continue;
            if(expression[i] == '!' || expression[i] == '&' || expression[i] == '|')
            {
                st1.push(expression[i]);
                continue;
            }
            else if(expression[i] != ')' )
                st2.push(expression[i]);
            else
            {
                char c =  st1.top();
                st1.pop();
                bool ans = false;
                if(st2.top() == 't')
                    ans = true;
                else
                    ans = false;
                st2.pop();
                while(!st2.empty() && st2.top() != '(')
                {
                    if(c == '|')
                    {
                        if(st2.top() == 't')
                            ans |= true;
                        else
                            ans |= false;
                    }
                    else if(c == '&')
                    {
                        if(st2.top() == 't')
                            ans &= true;
                        else
                             ans &= false;
                    }
                    st2.pop();
                }
                if(c == '!')
                    ans = !ans;
                if(st2.top() == '(')
                    st2.pop();
                if(ans == false)
                    st2.push('f');
                else
                    st2.push('t');
            }
        }
        if(st2.top() == 'f')
            return false;
        return true;
        
    }
};