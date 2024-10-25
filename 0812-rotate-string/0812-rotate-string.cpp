class Solution {
public:
    bool rotateString(string s, string goal) {
        if(goal.size()<s.size())
            return false;
        string m = s;
        s = s+"#"+goal;
        string x = s+"#"+goal;
        cout<<s<<" \n";
        vector<int>v(s.size()+goal.size()+1,0);
        int sz = v.size();
        int k = 0;
        for(int i = 1; i<v.size(); i++)
        {
            while(k>0 && x[i]  != x[k])
            {
                k = v[k-1];
            }

            if(x[i] == x[k])
                v[i] = ++k;
            else
                v[i] = k;
        }
        int j = 0; 
        for(int i = v[v.size()-1]; i< m.size(); i++)
        {
            if(m[i] != goal[j++])
                return false;
        }

        return true;
        
        
    }
};