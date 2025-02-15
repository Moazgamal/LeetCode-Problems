class Solution {
    bool fn(int idx , int cursum, string &s, int target)
    {
        if(cursum== target && idx >= s.size())
            return true;
        
        if(cursum > target)
            return false;
        string str = "";
        for(int i = idx; i< s.size(); i++)
        {
            str.push_back(s[i]);
            if(fn(i+1, cursum+stoi(str) , s, target))
                return true;
        }
        return false;
    } 
public:
    int punishmentNumber(int n) {
        int ans = 0; 
        for(int i = 1; i<=n; i++)
        {
            int dup = i*i;
            string s = to_string(dup);
            int limit = to_string(i).size();
            bool f = fn(0,0,s,i);
            if(f==true)
                ans+=dup;
        }return ans;
        
    }
};