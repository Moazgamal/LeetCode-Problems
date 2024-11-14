class Solution {
    bool fn(int mid, int n, vector<int>&quantities)
    {
        int i = 0;
        for( ;i< quantities.size() && n>0; i++)
        {
            int x = quantities[i];
            if(mid>=x)
            {
                n--;continue;
            }
            else
            {
                while(n>0 && x>0)
                {
                    n--; x-=mid;
                }
                if(n<=0 && x>0)
                    return false;
            }
        }
        if(i>= quantities.size() && n>=0)
            return true;
        return false;
    }
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start = 1; int end = 100001;
        int mid = -1; int pos = -1;
        while(start<=end)
        {
            mid = start+ (end-start)/2;
            if(fn(mid, n, quantities))
            {
                pos=mid;
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }return pos;
        
    }
};