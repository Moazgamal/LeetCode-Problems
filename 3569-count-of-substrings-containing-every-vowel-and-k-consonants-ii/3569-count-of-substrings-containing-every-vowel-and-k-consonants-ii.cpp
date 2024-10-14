class Solution {
            bool isvowel(char func)
        {
        
        if(func =='a')
                return 1;
        if(func =='e')
                return 1;
        if(func =='i')
                return 1;
        if(func =='o')
                return 1;
        if(func =='u')
                return 1;
        if(func =='A')
                return 1;
        if(func =='E')
                return 1;
        if(func =='I')
                return 1;
        if(func =='O')
                return 1;
        if(func =='U')
                return 1;
        else
                return 0;
        }
public:
    long long countOfSubstrings(string word, int k) {
        
        vector<int> indices(word.size());
        int next = word.size();
        for(int i = word.size()-1; i>=0; i--)
        {
            indices[i] = next;
            if(!isvowel(word[i]))
                next = i;
        }
        int j = 0;
        int cons = 0; 
        unordered_map<char,int> mp;
        long long ans = 0;
        for(int i = 0 ; i< word.size(); i++)
        {
            if(isvowel(word[i]))
                {
                    mp[word[i]]++;
                }
            else
                cons++;
            if(cons>k)
            {
                while(j<=i && cons >k)
                {
                    if(isvowel(word[j]))
                    {
                        mp[word[j]]--;
                        if(mp[word[j]] == 0)
                            mp.erase(word[j]);
                    }
                    else
                        cons--;
                    j++;
                }
                
            }
        while(j<i&&mp.size() == 5 && cons == k)
            {
                int next = indices[i];
                ans += (next-i);
                if(isvowel(word[j]))
                {
                    if(--mp[word[j]] ==0)
                        mp.erase(word[j]);
                }
                else
                    cons--;
                j++;
            }
            
        }
        return ans;

    }
};