class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {


        unordered_map<int,int>mp;
        for(int i = 0; i< banned.size(); i++)
        {
            mp[banned[i]]++;
        }
        int cnt = 0; int sum = 0;
        for(int i = 1; i<=n ; i++)
        {
            if(mp.count(i) == 0 && sum+i <= maxSum)
            {
                cnt++ ; sum+=i;
            }
            else if(sum+i > maxSum)
                break;
            
        }
        return cnt;
        
    }
};