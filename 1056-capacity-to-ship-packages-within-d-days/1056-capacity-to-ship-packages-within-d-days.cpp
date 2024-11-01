class Solution {
    bool fn(int mid, vector<int>&weights, int days)
    {
        int cnt = 1; 
        int sum = 0;
        for(int i = 0; i< weights.size(); i++)
        {
            if(weights[i]> mid)
                return false;
            sum+=weights[i];
            if(sum>mid)
            {
                sum= weights[i];
                cnt++;
            }
        }
        if(cnt >days)
            return false;
        return true;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {


        int l = 1; int r = 500*50001+2;
        int pos = -1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(fn(mid, weights, days))
            {
                pos = mid;
                r = mid-1;
            }
            else
                l = mid+1;
        }return pos;
        
    }
};