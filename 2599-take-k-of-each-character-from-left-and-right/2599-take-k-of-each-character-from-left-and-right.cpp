class Solution {
    bool fn(int mid, string &s, int k)
    {
        unordered_map<char,int>mp;
        int i = 0;
        for( ;i<mid; i++)
        {
            mp[s[i]]++;
        }
        i--;
        if(mp['a']>=k && mp['b'] >=k && mp['c'] >=k)
            return true;
        for(int j = s.size()-1; i>=0; j--, i--)
        {
            mp[s[i]]--; mp[s[j]]++;
            if(mp['a']>=k && mp['b'] >=k && mp['c'] >=k)
                return true;
        }
        return false;
    }
public:
    int takeCharacters(string s, int k) {
        if(k==0)
            return 0; 
        int start = 3; int end = s.size();
        int pos = -1; int mid = -1;
        while(start<=end)
        {
            mid= start+(end-start)/2;
            if(fn(mid,s,k))
            {
                pos = mid;
                end=mid-1;
            }
            else
            {
                cout<<mid<<" \n";
                start =mid+1;
            }
        }return pos;
    }
};