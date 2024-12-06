class Solution {
    void distributeleft(vector<int> &v, string &target, stack<int>lcopy)
    {
        for(int i =0; i< target.size(); i++)
        {
            if(target[i] == 'L')
            {
                int idx = lcopy.top(); lcopy.pop();
                if(i-1>=0)
                {
                    if(v[i-1] >0)
                        v[i-1]++;
                    else
                        v[i]++;
                }
                else
                    v[i]++;
                v[idx]--;
            }
        }
    }
    void distributeright(vector<int> &v, string &target, stack<int>Rcopy)
    {
        for(int i =target.size()-1; i>=0; i--)
        {
            if(target[i] == 'R')
            {
                int idx = Rcopy.top(); Rcopy.pop();
                if(i+1<target.size())
                {
                    if(v[i+1] >0)
                        v[i+1]++;
                    else
                        v[i]++;
                }
                else
                    v[i]++;
                v[idx]--;
            }
        }
    }

    bool checkright(stack<int> rights, string &target)
    {
         for(int i = target.size()-1; i>=0; i--)
        {
            if(target[i] == 'R')
            {
                if(rights.empty() || rights.top() >i)
                    return false;
                rights.pop();
            }
        }
        return rights.empty();
    }
    bool checkleft(stack<int> lefts, string &target)
    {
        for(int i = 0; i< target.size(); i++)
        {
            if(target[i] == 'L')
            {
                if(lefts.empty() || lefts.top() < i)
                    return false;
                lefts.pop();
            }
        }
        return lefts.empty();
    }
public:
    bool canChange(string start, string target) {
        stack<int> lefts;
        stack<int> rights;
        for(int i = start.size()-1; i>=0 ; i--)
        {
            if(start[i] == 'L')
                lefts.push(i);
        }
        for(int i = 0; i< start.size(); i++)
        {
            if(start[i] == 'R')
                rights.push(i);
        }
        if(!checkleft(lefts, target) || !checkright(rights, target))
            return false;
        vector<int> v(start.size(), 0);
        distributeleft(v, target, lefts);
        int prefix = 0; 
        string newstring = start;
        for(int i = 0; i< v.size(); i++)
        {
            if(start[i] == 'L')
            {
                prefix += v[i];
                newstring[i] = '_';
                continue;
            }
            prefix += v[i];
            newstring[i+prefix] = start[i];
        }
        for(int i = 0; i< target.size(); i++)
        {
            if(target[i] == 'L')
                newstring[i] = 'L';
        }
        cout<<newstring<<" newstring\n";
        stack<int> r;
        for(int i = 0; i< newstring.size(); i++)
        {
            if(newstring[i] == 'R')
                r.push(i);
        }
        if(!checkright(r, target))
            return false;
       vector<int>v2(start.size(),0);
     distributeright(v2,target,r);
        prefix = 0; 
        string x = newstring;
        for(int i = v2.size()-1; i>=0; i--)
        {
            if(newstring[i] == 'R')
            {
                prefix += v2[i];
                x[i] = '_';
            
                continue;
            }
            prefix += v2[i];
            x[i-prefix] = newstring[i];
        }
        cout<<x<<" xbefore\n";
        for(int i = 0; i< target.size(); i++)
        {
            if(target[i] == 'R')
                x[i] = 'R';
        }
        cout<<x;
        for(int i = 0; i< target.size(); i++)
        {
            if(target[i] == 'L' && x[i] != 'L' )
                return false;
            if(target[i] == 'R' && x[i] != 'R')
                return false;
            if(target[i] != x[i])
                return false;
        }return true;



        
    }
};