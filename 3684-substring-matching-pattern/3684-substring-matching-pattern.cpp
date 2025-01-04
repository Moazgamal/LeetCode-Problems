class Solution {
public:
    bool hasMatch(string s, string p) {
        if(p[p.size()-1] == '*')
        {
            int sz = p.size()-1;
            for(int i =0; i<= s.size()-sz+1; i++)
                {
                    if(s.substr(i,sz) == p.substr(0,sz))
                        return true;
                }
            return false;
        }
        if(p[0] == '*')
        {
            int sz = p.size()-1;
            for(int i =0; i<= s.size()-sz+1; i++)
                {
                    if(s.substr(i,sz) == p.substr(1,sz))
                        return true;
                }
            return false;
        }
        int i = 0;
        for( ;i< p.size(); i++)
            {
                if(p[i] == '*')
                    break;
            }
        int sz = (p.size()-i)-1;
        int f = i+1;
        bool status = false;
        int j = 0;
        for( ;j<= s.size()-i+1; j++)
            {
                if(s.substr(j,i) == p.substr(0,i))
                {
                    status = true;
                    break;
                }
            }
        if(status == false)
            return false;
        for(int k = j+i; k<=s.size()-sz+1; k++)
            {
                if(s.substr(k,sz) == p.substr(f,sz))
                    return true;
            }
        return false;
        
    }
};