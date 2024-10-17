class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        vector<int>v (s.size(),-1);
        int maxi=s.size()-1;
        for(int i = s.size()-2; i>=0; i--)
        {
            if(s[i]-'0' < s[maxi]-'0')
            {
                v[i]=maxi;
            }
            else if(s[i]-'0' > s[maxi]-'0')
            {
                maxi=i;
            }
        }
        for(int i = 0; i< v.size(); i++)
        {
            if(v[i] !=-1)
            {
                swap(s[i], s[v[i]]);
                break;
            }
        }
        stringstream ss; ss<<s; int x = 0; ss>>x; return x;
    }
};