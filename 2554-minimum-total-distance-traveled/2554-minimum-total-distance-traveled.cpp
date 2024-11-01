class Solution {
    long long fn(int ir, int ifa, vector<int>&robot, vector<int>&f, vector<vector<long long>>&dp)
    {
        if(ir >= robot.size())
            return 0;
        if(ifa >= f.size())
            return LLONG_MAX/2;
        long long &ret = dp[ir][ifa];
        if(ret != -1)
            return ret;
        // take
        int diff =0;
        if(ifa>ir)
            diff=abs(f[ifa]-robot[ir]);
        else
            diff= abs(robot[ir]-f[ifa]);
        long long take =  diff +fn(ir+1, ifa+1, robot, f, dp);
        long long leave = fn(ir, ifa+1, robot, f, dp);
        return ret = min(take, leave);
    }
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {


        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        vector<int>f;
        for(int i = 0; i< factory.size(); i++)
        {
            while(factory[i][1]--)
            {
                f.push_back(factory[i][0]);
            }
        }
        vector<vector<long long>>dp(robot.size(), vector<long long>(f.size(), -1));

        return fn(0,0, robot, f, dp);
        
    }
};