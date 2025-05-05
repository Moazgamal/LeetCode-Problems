using g  = vector<vector<int>>;
using v  = vector<int>;
class Solution {
    void build(int r, int cmax, int N, int &cnt, g &ans)
    {
        if(N == 2)
        {
            ans[r][cmax] = cnt++;
            ans[r+1][cmax] = cnt++;
            ans[r+1][cmax-1] = cnt++;
            ans[r][cmax-1] = cnt++;
            return ;
        }
        int x = N/2;
        for(int i = 0; i< 4; i++)
        {
            build(r, cmax, x, cnt, ans);
            if(i== 0)
                r+= x;
            if(i==1)
                cmax -= x;
            if(i==2)
                r -= x;
        }
    }
public:
    vector<vector<int>> specialGrid(int N) {
        if(N ==0)
            return {{0}};
        int sz = 1<<N;
        g ans(sz, v(sz,0));
        int cnt = 0; 
        build(0, sz-1, sz, cnt, ans);
        return ans;
        
        
    }
};