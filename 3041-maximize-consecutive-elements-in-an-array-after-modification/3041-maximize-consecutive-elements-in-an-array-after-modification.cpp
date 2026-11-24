class Solution {
    void fn(unordered_map<int,bool>&vis, map<int,int>&mp,
    int curVal, int &ans)
    {
       int lastMiss = -1; int lastDup = -1;
       int cnt = 0;
       while(true)
       {
            if(mp.count(curVal) > 0)
            {
                cnt++;
                if(mp[curVal]>1)
                    lastDup = curVal;
                ans = max(ans, cnt);
                vis[curVal]=true;
                curVal++;
            }
            else
            {
                if(curVal - lastMiss  == 1)
                    return;
                if(lastDup > lastMiss)
                {
                    cnt++; ans = max(ans, cnt);
                    lastMiss = curVal;
                    curVal++;
                }
                else if(lastDup == lastMiss)
                {
                    lastMiss = curVal;
                    curVal++;
                }
                else
                {
                    cnt = curVal - lastMiss -1;
                    ans = max(ans, cnt);
                    lastMiss = curVal;
                    curVal++;
                }
            }
       }
    }
public:
    int maxSelectedElements(vector<int>& nums) {

        map<int,int>mp;
        for(int i = 0; i< nums.size(); i++)
            mp[nums[i]]++;
        
        unordered_map<int,bool>vis;
        int ans = 1;
        for(auto &j: mp)
        {
            if(vis[j.first] == false)
            {
                fn(vis, mp, j.first,  ans);
            }
        }
        return ans; 
    }
};