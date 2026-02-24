class Solution {
    void fn(string &str, unordered_map<string, bool>&mp, int &k, bool &ans)
    {
        if(str.size()== k)
        {
            cout<<str<<" ";
            if(mp.count(str) == 0)
                ans = false;
            return ;
        }
        if(ans == false)
            return; 
        str.push_back('0');
        fn(str, mp,k,ans);
        cout<<str<<" s";
        if(ans == false)
            return;
        str.pop_back();
        str.push_back('1');
        fn(str, mp,k,ans);
        str.pop_back();
        if(ans == false)
            return; 
    }
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k)
            return false; 
        unordered_map<string,bool>mp;
        for(int i = 0; i <= s.size()-k; i++)
            mp[s.substr(i,k)]=true;

        string str = "";
        bool ans = true; 
        fn(str,mp,k,ans);
        return ans; 
    }
};