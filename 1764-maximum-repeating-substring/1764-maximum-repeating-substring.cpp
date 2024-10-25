class Solution {
    vector<int> fn(string &s)
    {
        vector<int> longestk(s.size(), 0);
        for(int i =1, k=0; i<s.size(); i++)
        {
            while(k>0 && s[i] != s[k])
            {
                k= longestk[k-1];
            }
            if(s[i] == s[k])
            {
                longestk[i] = ++k;
            }
            else
                longestk[i] = k;
        }return longestk;
    }
    unordered_map<int,int> fn2(string &str, string &pat, vector<int>&longestk)
    {
        unordered_map<int,int>mp;
        for(int i = 0, k=0; i< str.size(); i++)
        {
            while(k>0 && str[i] != pat[k])
            {
                k= longestk[k-1];
            }
            if(str[i]== pat[k])
                k++;
            if(k== pat.size())
            {
                mp[i-pat.size()+1]++;
                k= longestk[k-1];
            }
        }return mp;
    }
public:
    int maxRepeating(string sequence, string word) {

        vector<int> longestk = fn(word);
        unordered_map<int,int> mp = fn2(sequence, word, longestk);
        int sz = word.size();
        if(mp.size() ==0)
            return 0;
        int maxi = 1;
        int ans = 1; 

        for(auto i: mp)
        {
            int no = i.first+sz;
            cout<<no<<" \n";
            while(mp.count(no) >0)
            {
                ans++;
                if(mp.count(no+sz)>0)
                    no = no+sz;
                else
                    break;
            }
            maxi=max(ans,maxi);
            ans=1;
        }return maxi;

        
    }
};