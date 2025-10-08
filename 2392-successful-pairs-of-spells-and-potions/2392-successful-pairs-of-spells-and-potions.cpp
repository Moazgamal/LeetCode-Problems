class Solution {
    int fn(int target, vector<int>&p, long long &s)
    {
        int start = 0; int end = (int)p.size()-1;
        int mid = -1; int pos = -1; 
        while(start <= end)
        {
            mid = start + (end-start)/2;
            long long m = (long long)target*p[mid];
            if(m>=s)
            {
                pos = mid;
                start = mid+1;
            }
            else
            {
                end = mid-1;
            }
        }
        return pos;
    }
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>ans(spells.size());
        sort(potions.rbegin(), potions.rend());
        for(int i = 0; i< spells.size(); i++)
        {
            int x = fn(spells[i], potions, success);
            if(x != -1)
            {
                ans[i] = x+1;
            }
        }return ans; 

        
    }
};