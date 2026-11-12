class Solution {
public:
    long long appealSum(string s) {

        long long ans = 0; 
        unordered_map<char,queue<int>>mp;
        int unique = 0; 
        for(int i = 0; i< s.size(); i++)
        {
            if(mp.count(s[i]) ==0)
                unique++;
            mp[s[i]].push(i);
            ans += unique;
        }
        int firstAns = ans;
        for(int i = 0; i< s.size(); i++)
        {
            int i1 = s.size();
            mp[s[i]].pop();
            if(!mp[s[i]].empty())
                i1 = mp[s[i]].front();
            
            firstAns -= (i1-i);
            ans += firstAns;
        }   
        return ans; 
    }
};