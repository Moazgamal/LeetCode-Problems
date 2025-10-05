class Solution {
    bool fn(int mid, vector<int>&price, int k)
    {
        int last = price[0];
        k--;
        for(int i =1; i< price.size() && k>0; i++)
        {
            if(price[i] - last >= mid)
            {
                k--; last = price[i];
            }
        }
        return k== 0; 
    }
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int ans = 0;
        int start = 0; int end = price[price.size()-1] - price[0];
        int mid = -1; 
        while(start <= end)
        {
            mid = start + (end-start)/2;
            if(fn(mid, price, k))
            {
                ans = mid;
                start = mid+1; 
            }
            else
            {
                end = mid-1; 
            }
        }
        return ans; 
    }
};