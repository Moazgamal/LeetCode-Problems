class Solution {
    bool isVowel(char ch) {
    ch = tolower(ch); // Convert to lowercase to handle uppercase letters
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}
public:
    long long countOfSubstrings(string word, int k) {
        long long ans = 0; 
        int cons = 0; 
        unordered_map<char,int>mp;
        int j = 0; 
        vector<int> consInd(word.size());
        consInd[consInd.size()-1]= consInd.size();
        int lastConsIdx = consInd.size();
        if(!isVowel(word[word.size()-1]))
             lastConsIdx = word.size()-1;
        
        for(int i = word.size()-2; i>=0;i--)
        {
            consInd[i]= lastConsIdx;
            if(!isVowel(word[i]))
                lastConsIdx = i; 
        }
        for(int i = 0; j< word.size(); )
        {
            if(isVowel(word[j]))
            {
                mp[word[j]]++;
            }
            else
                cons++;
            while(mp.size()==5 && cons>=k)
            {
                if(cons==k)
                {
                    int idx = consInd[j];
                    cout<<idx<<"  \n";
                    while(mp.size()==5 && cons == k)
                    {
                        ans += (idx-j);
                        if(isVowel(word[i]))
                        {
                            mp[word[i]]--;
                            if(mp[word[i]]==0)
                                mp.erase(word[i]);
                        }
                        else
                        {
                            cons--; 
                        }
                        i++;
                    }
                }
                else if(cons >k )
                {
                    while(cons > k)
                    {
                        if(isVowel(word[i]))
                        {
                            mp[word[i]]--;
                            if(mp[word[i]]==0)
                                mp.erase(word[i]);
                        }
                        else
                        {
                            cons--; 
                        }
                        i++;
                    }
                }
            }
            j++;
        }
        return ans; 
        
    }
};