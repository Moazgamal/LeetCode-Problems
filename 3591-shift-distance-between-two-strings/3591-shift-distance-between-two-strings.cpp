class Solution {
public:
    long long shiftDistance(string s, string t, vector<int>& nextCost, vector<int>& previousCost) {
        
        long long ans = 0; 
        vector<long long>prefixPrev(26,0);
        vector<long long>prefixNext(26,0);
        long long p1 = 0; long long p2  =0; 
        vector<vector<long long>>dp(26,vector<long long>(26,-1));
        for(int i = 0; i< 26; i++)
        {
            p1 += previousCost[i]; p2  +=nextCost[i];
            prefixPrev[i]=p1; prefixNext[i]=p2;
        }
        for(int i = 0; i< s.size(); i++)
        {
            long long minCost = LLONG_MAX;
            int idx1 = s[i]-'a'; int idx2 = t[i] - 'a';
            if(idx1== idx2)
                continue;
            if(dp[idx1][idx2]!=-1)
            {
                ans+=dp[idx1][idx2];
                continue;
            }
            if(idx1<idx2)
            {
                long long cost1 = prefixNext[idx2-1];
                if(idx1>0)
                    cost1 -= prefixNext[idx1-1];
                minCost = min(minCost, cost1);
                long long cost2 = prefixPrev[idx1];
                if(idx2+1<26)
                    cost2+=prefixPrev[25]-prefixPrev[idx2];
                minCost = min(minCost, cost2);
            }
            if(idx1>idx2)
            {
                long long cost1 = prefixPrev[idx1];
                cost1 -= prefixPrev[idx2];
                minCost = min(minCost, cost1);
                long long cost2 = prefixNext[25]-prefixNext[idx1-1];
               if(idx2-1>=0)
                cost2 +=prefixNext[idx2-1];
                minCost = min(minCost, cost2);

            }
            ans+=minCost;
            dp[idx1][idx2]=minCost;
        }return ans;
    }
};