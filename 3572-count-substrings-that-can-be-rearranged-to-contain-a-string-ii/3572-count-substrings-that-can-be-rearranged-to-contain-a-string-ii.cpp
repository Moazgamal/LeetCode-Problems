class Solution {
public:
    long long validSubstringCount(string word1, string word2) {

        unordered_map<char,int> mp;
        unordered_map<char,int>mp2;
        for(int i = 0; i< word2.size(); i++)
        {
            mp2[word2[i]]++;
        }
        int j = 0; 
        long long ans = 0;
        for(int i = 0; i< word1.size(); i++)
        {
            mp[word1[i]]++;
            int cnt=0;
            for(auto x: mp2)
            {
                if(mp.count(x.first) >0 && mp[x.first]>=x.second)
                {
                    cnt++;
                }
                else
                    break;
            }
            if(cnt==mp2.size())
            {
                ans+=(word1.size()-i);
                
                while(j<=i && mp[word1[j]] >= mp2[word1[j]])
                {
                    if(mp[word1[j]] >mp2[word1[j]])
                        {
                            ans+=(word1.size()-i);
                            mp[word1[j]]--;
                            j++;

                        }
                    else
                    {
                        mp[word1[j]]--;
                        j++;
                        break;

                    }
                    
                    
                }
                
                    
                
                
            }
        }return ans;
        
    }
};