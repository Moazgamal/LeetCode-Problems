class Solution {
    void fn(int idx, vector<int>&arr, int &d, unordered_map<int,bool>&mp
    , int moves, int &ans)
    {
        ans = max(ans, moves); 
        int start = max(0,  idx-d);
        int end = min((int)arr.size()-1, idx+d);
        int maxsofar = -1; 
        for(int i = idx-1; i>=start; i--)
        {
            if(arr[idx]<= arr[i])
                break;
            if(arr[idx]>arr[i] && arr[i]>=maxsofar)
            {
                maxsofar = arr[i];
                fn(i, arr, d, mp, moves+1, ans);
            }
        }
        maxsofar = -1;
        for(int i = idx+1; i<=end; i++)
        {
            if(arr[idx]<= arr[i])
                break;
            if(arr[idx]>arr[i]  && arr[i]>=maxsofar)
            {
                maxsofar = arr[i];
                fn(i, arr, d, mp, moves+1, ans);
            }
        }
        mp[idx]= false; 
    }
public:
    int maxJumps(vector<int>& arr, int d) {

        int ans = 0; 
        for(int i = 0; i< arr.size(); i++)
        {
            int moves = 1; 
            unordered_map<int,bool>mp;
            fn(i, arr, d, mp, moves, ans);
        }
        return ans; 
        
    }
};