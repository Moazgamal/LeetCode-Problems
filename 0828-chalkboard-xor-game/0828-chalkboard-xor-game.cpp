class Solution {
    int fn(int num)
    {
        int ans = 0; 
        while(num>0)
        {
            if(num %2 == 1)
                ans++;

            num/=2;
        }
        return ans; 
    }
    void fn2(int num, unordered_map<int,vector<int>>&mp, vector<int>&Bits)
    {
        int cnt = 0; 
        int orgNum = num;
        while(num>0)
        {
            if(num %2 == 1)
            {
                Bits[cnt]++;
                mp[orgNum].push_back(cnt);
            }
            num/=2;
            cnt++;
        }
    }
    bool fn3(int &totalBits, unordered_map<int,int>&freq, unordered_map<int,vector<int>>&mp
    , vector<int>&bitsOfDigit)
    {
        int orgTotalBits = totalBits;
        for(auto x:freq)
        {
            if(x.first == 0)
                continue;
            int f = x.first;
            for(auto y: mp[f])
            {
                bitsOfDigit[y]--;
                if(bitsOfDigit[y]%2 ==0)
                {
                    totalBits--;
                }
                else
                {
                    totalBits++;
                }
            }
            if(totalBits%2 != 0 && totalBits > 0)
            {
                freq[f]--;
                if(freq[f] == 0)
                {
                    freq.erase(f);
                }
                return true;
            }
            for(auto y: mp[f])
            {
                bitsOfDigit[y]++;
            }
            totalBits = orgTotalBits;
        }
        return false; 
    }
public:
    bool xorGame(vector<int>& nums) {
        unordered_map<int,int>freq;
        unordered_map<int,vector<int>>mp;
        int totalXor = 0;
        vector<int>bitsOfDigit(17,0);
        for(int i =0;i< nums.size(); i++)
        {
            freq[nums[i]]++;
            if(mp.count(nums[i]) == 0)
            {
                fn2(nums[i], mp, bitsOfDigit);
            }
            else
            {
                for(auto h: mp[nums[i]])
                {
                    bitsOfDigit[h]++;
                }
            }
            totalXor ^= nums[i];
        }
        
        int totalBits = fn(totalXor);
        
        bool Alice = true;
        if(totalXor == 0)
            return true;
        while(true)
        {
            if(Alice)
            {
                if(totalBits%2 !=0)
                {
                    if(freq[0] >0)
                    {
                        freq[0]--; 
                        Alice = !Alice; continue;
                    }
                    else
                    {
                        if(fn3(totalBits, freq, mp, bitsOfDigit))
                        {
                            Alice = !Alice; continue;
                        }
                        else
                            return false; 
                    }
                }
                else
                {
                    if(fn3(totalBits, freq, mp, bitsOfDigit))
                    {
                        Alice = !Alice; continue;
                    }
                    // else if(freq[0]>0)
                    // {
                    //     freq[0]--; Alice = !Alice; continue;
                    // }
                    else
                        return false; 
                }
            }
            else
            {
                if(totalBits%2 !=0)
                {
                    if(freq[0] >0)
                    {
                        freq[0]--; 
                        Alice = !Alice; continue;
                    }
                    else
                    {
                        if(fn3(totalBits, freq, mp, bitsOfDigit))
                        {
                            Alice = !Alice; continue;
                        }
                        else
                            return true; 
                    }
                }
                else
                {
                    if(fn3(totalBits, freq, mp, bitsOfDigit))
                    {
                        Alice = !Alice; continue;
                    }
                    // else if(freq[0]>0)
                    // {
                    //     freq[0]--; Alice = !Alice; continue;
                    // }
                    else
                        return true; 
                }
            }
        }
        return true;
        
    }
};




// map<int,int, greater<int>>evensEvens;
        // map<int,int, greater<int>>evensOdds;
        // map<int,int, greater<int>>oddsEvens;
        // map<int,int, greater<int>>oddsOdds;


// for(auto x: freq)
        // {
        //     if(x.first == 0)
        //         continue;
        //     if(x.second%2 == 0)
        //     {
        //         int setBits = fn(x.first);
        //         if(setBits%2 == 0)
        //             evensEvens[x.second] = setBits;
        //         else
        //             evensOdds[x.second] = setBits;
        //     }
        //     else
        //     {
        //         int setBits = fn(x.first);
        //         if(setBits%2 == 0)
        //             oddsEvens[x.second] = setBits;
        //         else
        //             oddsOdds[x.second] = setBits;
        //     }
        // }



// while(true)
        // {
        //     if(Alice)
        //     {
        //         if(totalBits %2 !=0)
        //         {
        //             bool f = false;
        //             if(freq[0]>0)
        //             {
        //                 freq[0]--; Alice = !Alice; continue;
        //             }
        //             if(evensEvens.size() >0)
        //             {
        //                 auto it = evensEvens.begin();
        //                 int numFreq = it->first; int numBits = it->second;
        //                 totalBits += numBits;
        //                 evensEvens.erase(numFreq);
        //                 oddsEvens[numFreq-1] = numBits;
        //                 Alice = !Alice;
        //                 f = true; 
        //             }
        //             if(f == false)
        //             {
        //                 if(oddsEvens.size() == 0)
        //                 {
        //                     return false; 
        //                 }
        //                 auto it = oddsEvens.begin();
        //                 int numFreq = it->first; int numBits = it->second;
        //                 if(totalBits-numBits <=0)
        //                     return false; 
        //                 totalBits -= numBits;
        //                 oddsEvens.erase(numFreq);
        //                 if(numFreq-1>0)
        //                     evensEvens[numFreq-1] = numBits;
        //                 Alice = !Alice;
        //             }
        //         }
        //         else
        //         {
        //             bool f = false;
        //             // if(evensOdds.size() == 0 && oddsOdds.size() == 0)
        //             // {
        //             //     if(freq[0] == 0)
        //             //         return false;
        //             //     freq[0]--;
        //             //     Alice = !Alice
        //             //     continue;
        //             // }
        //             if(evensOdds.size() >0)
        //             {
        //                 auto it = evensOdds.begin();
        //                 int numFreq = it->first; int numBits = it->second;
        //                 totalBits += numBits;
        //                 evensOdds.erase(numFreq);
        //                 oddsOdds[numFreq-1] = numBits;
        //                 Alice = !Alice;
        //                 f = true; 
        //             }
        //             if(f == false)
        //             {
        //                 auto it = oddsOdds.begin();
        //                 int numFreq = it->first; int numBits = it->second;
        //                 if(totalBits-numBits >0)
        //                 {
        //                     totalBits -= numBits;
        //                     oddsOdds.erase(numFreq);
        //                     if(numFreq-1>0)
        //                         evensOdds[numFreq-1] = numBits;
        //                     Alice = !Alice;
        //                     f = true; 
        //                 }
        //             }
        //             if(f == false)
        //             {
        //                 if(freq[0]>0)
        //                 {
        //                     freq[0]--; Alice = !Alice; continue;
        //                 }
        //                 else
        //                     return false; 
        //             }
        //         }
        //     }
        //     else
        //     {
        //         if(totalBits %2 !=0)
        //         {
        //             bool f = false;
        //             if(freq[0]>0)
        //             {
        //                 freq[0]--; Alice = !Alice; continue;
        //             }
        //             if(evensEvens.size() >0)
        //             {
        //                 auto it = evensEvens.begin();
        //                 int numFreq = it->first; int numBits = it->second;
        //                 totalBits += numBits;
        //                 evensEvens.erase(numFreq);
        //                 oddsEvens[numFreq-1] = numBits;
        //                 Alice = !Alice;
        //                 f = true; 
        //             }
        //             if(f == false)
        //             {
        //                 if(oddsEvens.size() == 0)
        //                 {
        //                     return true; 
        //                 }
        //                 auto it = oddsEvens.begin();
        //                 int numFreq = it->first; int numBits = it->second;
        //                 if(totalBits-numBits <=0)
        //                     return true; 
        //                 totalBits -= numBits;
        //                 oddsEvens.erase(numFreq);
        //                 if(numFreq-1>0)
        //                     evensEvens[numFreq-1] = numBits;
        //                 Alice = !Alice;
        //             }
        //         }
        //         else
        //         {
        //             bool f = false;
        //             // if(evensOdds.size() == 0 && oddsOdds.size() == 0)
        //             // {
        //             //     if(freq[0] == 0)
        //             //         return false;
        //             //     freq[0]--;
        //             //     Alice = !Alice
        //             //     continue;
        //             // }
        //             if(evensOdds.size() >0)
        //             {
        //                 auto it = evensOdds.begin();
        //                 int numFreq = it->first; int numBits = it->second;
        //                 totalBits += numBits;
        //                 evensOdds.erase(numFreq);
        //                 oddsOdds[numFreq-1] = numBits;
        //                 Alice = !Alice;
        //                 f = true; 
        //             }
        //             if(f == false)
        //             {
        //                 auto it = oddsOdds.begin();
        //                 int numFreq = it->first; int numBits = it->second;
        //                 if(totalBits-numBits >0)
        //                 {
        //                     totalBits -= numBits;
        //                     oddsOdds.erase(numFreq);
        //                     if(numFreq-1>0)
        //                         evensOdds[numFreq-1] = numBits;
        //                     Alice = !Alice;
        //                     f = true; 
        //                 }
        //             }
        //             if(f == false)
        //             {
        //                 if(freq[0]>0)
        //                 {
        //                     freq[0]--; Alice = !Alice; continue;
        //                 }
        //                 else
        //                     return true; 
        //             }
        //         }
        //     }
        // }

