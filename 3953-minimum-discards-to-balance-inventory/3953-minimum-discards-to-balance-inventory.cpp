class Solution {
public:
    int minArrivalsToDiscard(vector<int>& arrivals, int w, int m) {
        unordered_map<int,int>mp;
        unordered_map<int,int>mp2;
        int ans = 0; 
        int lastMin = 1; 
        for(int i = 0; i< arrivals.size(); i++)
        {
            int maxDay = i+1; 
            int minDay = max(1, (i+1)-w+1);
            mp[arrivals[i]]++;
            if(minDay != lastMin)
            {
                if(mp2.count(lastMin-1) ==0)
                {
                    mp[arrivals[lastMin-1]]--;
                }
                lastMin= minDay;
            }
            if(mp[arrivals[i]] >m)
            {
                mp[arrivals[i]]--;
                ans++; mp2[i]++;
            }
        }
        return ans; 

    }
};