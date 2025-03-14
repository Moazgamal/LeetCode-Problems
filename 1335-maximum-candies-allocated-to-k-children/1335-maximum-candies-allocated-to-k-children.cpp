class Solution {
    bool fn(long long mid , vector<int>&can, long long k)
    {
        for(int i =0; i< can.size(); i++)
        {
            long long val = can[i];
            k-= (val/mid);
            if(k<=0)
                return true;
        }
        return false;
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {

        long long start = 1; long long end = *std::max_element(candies.begin(), candies.end());
        long long mid = -1; long long pos =-1;

        while(start<=end)
        {
            mid= start + (end-start)/2;
            if(fn(mid, candies, k))
            {
                pos = mid;
                start = mid+1;
            }
            else
            {
                end= mid-1; 
            }

        }
        return pos>0?pos:0;
        
    }
};