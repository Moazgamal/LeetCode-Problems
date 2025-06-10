class Solution {
    int dp[3][51][51][51];
    int fn(int idx, int x, int y , int z, int &ans, int &x1, int &y1, int &z1)
    {
        if(idx == 0)
            x--;
        else if(idx == 1)
            y--;
        else
            z--;
        if(dp[idx][x][y][z] !=-1)
            return dp[idx][x][y][z];
        if(idx ==0)
        {
            if(y == 0)
            {
                int i = 2*((x1-x) + y1+(z1-z));
                // ans = max(ans,  i);
                return dp[idx][x][y][z] = 2*((x1-x) + y1+(z1-z)); 
            }
            else
            {
                return dp[idx][x][y][z] = fn(1, x, y, z, ans, x1, y1, z1);
            }
        }
        else if(idx == 1)
        {
            if(x ==0 && z ==0)
            {
                int i = 2*(x1+z1+(y1-y));
                // ans = max(ans, i);
                return dp[idx][x][y][z] = i; 
            }
            int c1 = 0; int c2 = 0; 
            if(z> 0)
            {
                c1 = fn(2, x,y,z,ans,x1,y1,z1);
            }
            if(x>0)
            {
                c2 = fn(0,x,y,z,ans,x1,y1,z1);
            }
            return dp[idx][x][y][z] = max(c1,c2);
        }
        else
        {
            if(x==0 && z==0)
            {
                int i = 2*(x1+ (z1-z) + (y1-y));
                // ans = max(ans, i);
                return dp[idx][x][y][z] = i;
            }
            int c1 = 0; int c2 = 0; 
            if(x>0)
            {
                c1 = fn(0, x,y,z,ans,x1,y1,z1);
            }
            if(z>0)
            {
                c2 = fn(2,x,y,z,ans,x1,y1,z1);
            }
            return dp[idx][x][y][z] = max(c1, c2);
        }
    }
public:
    int longestString(int x, int y, int z) {
        int ans = 0; 
        memset(dp, -1, sizeof(dp));
        int c1 = fn(0, x, y, z, ans,x,y,z);
        int c2 = fn(1, x, y, z, ans,x,y,z);
        int c3 = fn(2, x, y, z, ans,x,y,z);
        return max(c1, max(c2,c3));
        
    }
};