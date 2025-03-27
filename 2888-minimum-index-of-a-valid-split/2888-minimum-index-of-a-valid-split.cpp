class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int> mp1;
        map<int,int> mp2;
        map<int,unordered_set<int>, greater<int> > mp3;
        map<int,unordered_set<int>, greater<int> > mp4;
        for(int i = 0; i< nums.size(); i++)
        {
            mp1[nums[i]]++;
        }
        for(auto x: mp1)
        {
            mp3[x.second].insert(x.first); 
        }
        int ans = -1; 
        for(int i =0; i< nums.size()-1; i++)
        {
           mp1[nums[i]]--;
           mp2[nums[i]]++;
           int freq1= mp1[nums[i]];
           int freq2 = mp2[nums[i]];
            mp3[freq1+1].erase(nums[i]);
            if(mp3[freq1+1].size()==0)
                mp3.erase(freq1+1);
            if(freq1>0)
            {
                mp3[freq1].insert(nums[i]);
            }

            if(freq2>1)
            {
                mp4[freq2-1].erase(nums[i]);
                if(mp4[freq2-1].size() ==0)
                    mp4.erase(freq2-1);
                mp4[freq2].insert(nums[i]);
            }
            else
            {
                mp4[freq2].insert(nums[i]);
            }
            
            if(mp3.begin()->second.size() ==1 && mp4.begin()->second.size()==1)
            {
                
                if(*(mp3.begin()->second.begin()) == *(mp4.begin()->second.begin()))
                {
                    int f1= mp3.begin()->first;
                    int f2 = mp4.begin()->first;
                    int no1 = i+1;
                    int no2 = nums.size()-1 - i; 
                    no1 = no1/2+1;
                    no2 = no2/2+1;
                    if(f2>=no1 && f1>=no2)
                        return i ; 

                }
            }
        
        }
        return ans; 
    }
};