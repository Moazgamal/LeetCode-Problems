class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        unordered_map<char,int>mp;
        unordered_map<char,int>mp2;
        for(int i = 0; i< s1.size(); i++)
        {
            mp[s1[i]]++;
            mp2[s1[i]]++;
        }
        int j = 0;
        for(int i = 0; i< s2.size() ; i++)
        {
            if(mp.count(s2[i]))
            {
                if(mp2[s2[i]]-1 ==0)
                {
                    mp2.erase(s2[i]);
                    if(mp2.size() ==0)
                        return true;
                }
                else if(mp2[s2[i]]-1>0)
                {
                    mp2[s2[i]]--;
                    continue;
                }
                else
                {
                    mp2[s2[i]]--;
                    while(j<i && s2[j]!=s2[i])
                    {
                        ++mp2[s2[j]];
                        j++;
                    }

                    
                    mp2.erase(s2[j]);
                    j++;
                }

            }
            else
            {
                while(j<i)
                    {
                        ++mp2[s2[j]];
                        j++;
                    }
                    j++;
            }
        }
        return false;
        
    }
};