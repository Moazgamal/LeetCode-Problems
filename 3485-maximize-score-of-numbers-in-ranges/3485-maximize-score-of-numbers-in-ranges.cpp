class Solution {
    bool fn(long long mid, vector<int>&start, int &d)
    {
        long long  prev=start[0];
        for(int i=1 ; i<start.size(); i++){
            long long int next=max(prev+mid, static_cast<long long>(start[i]));
            if (next > start[i] + d) { 
                return false;
            }
            prev=next;
        }
        return true;
    }

public:
    int maxPossibleScore(vector<int>& start, int d) {
        sort(start.begin(), start.end());

        long long i = 0;
        long long j = start.back() - start.front() + d;
        int ans = -1;
        long long mid = -1;
        while(i<=j)
        {
             mid = i+(j-i)/2;
            if(fn(mid, start, d))
            {
                ans = mid;
                i = mid+1;
            }
            else
            {
                j= mid-1;
            }
        }
        return ans;


        
    }
};