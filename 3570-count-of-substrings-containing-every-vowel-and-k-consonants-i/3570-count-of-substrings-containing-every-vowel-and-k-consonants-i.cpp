class Solution {
    bool isvowel(char c)
    {
        if(c =='a' ||c=='e' || c=='i' || c== 'o' || c== 'u')
            return true;
        return false;
    }
public:
    int countOfSubstrings(string word, int k) {
        int cons= 0;
        int vows = 0; 
        unordered_map<char,int>mp;
        int j = 0; 
        int ans = 0;
        for(int i = 0; i< word.size(); i++)
        {
            if(isvowel(word[i]))
            {
                if(mp[word[i]] ==0)
                    vows++;
                mp[word[i]]++;
            }
            else
                cons++;
            if(vows<5 || cons<k)
                continue;
            
            if(cons == k && vows==5)
            {
                unordered_map<char,int> mp2 = mp;
                int _vows =5;
                int _cons=k;
                int _j=j;
                while(cons ==k && vows==5)
                {
                    ans++;
                    cout<<j<<"xxxxxxj\n";
                    if(isvowel(word[j]))
                    {
                        mp[word[j]]--;
                        if(mp[word[j]] ==0)
                            vows--;
                    }
                    else
                        cons--;
                    j++;
                }
                vows=5;
                cons = k;
                mp=mp2;
                j=_j;
            }
            else
            {
                while( cons >k)
                {
                    if(isvowel(word[j]))
                    {
                        mp[word[j]]--;
                        if(mp[word[j]]==0)
                            vows--;

                    }
                    else
                        cons--;
                  
                    
                    j++;
                }
                if(cons == k && vows==5)
            {
                unordered_map<char,int> mp2 = mp;
                int _vows =5;
                int _cons=k;
                int _j=j;
                while(cons ==k && vows==5)
                {
                    ans++;
                    cout<<j<<"xxxxxxj\n";
                    if(isvowel(word[j]))
                    {
                        mp[word[j]]--;
                        if(mp[word[j]] ==0)
                            vows--;
                    }
                    else
                        cons--;
                    j++;
                }
                vows=5;
                cons = k;
                mp=mp2;
                j=_j;
            }
               
               
            }
        }return ans;
        
    }
};