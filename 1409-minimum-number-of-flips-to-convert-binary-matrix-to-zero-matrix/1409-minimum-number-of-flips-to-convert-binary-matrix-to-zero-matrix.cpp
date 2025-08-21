class Solution {
public:
    int minFlips(vector<vector<int>>& mat) {

        queue<string>q;
        unordered_map<string,bool>mp;
        int ones = 0; 
        string str  = "";
        int rows = (int)mat.size(); int cols = (int)mat[0].size();
        for(int r = 0; r< mat.size(); r++)
        {
            for(int c= 0; c< mat[0].size(); c++)
            {
                if(mat[r][c] == 1)
                    ones++;
                str.push_back(mat[r][c]+'0');
            }
        }
        q.push(str);
        if(ones == 0)
            return 0; 
        int level = 0 ; 
        while(!q.empty())
        {
            int sz = (int)q.size();
            while(sz--)
            {
                auto cur = q.front(); 
                q.pop();
                mp[cur] = true; 
                int ones2 = 0; 
                for(int i = 0; i< (int)cur.size(); i++)
                {
                    if(cur[i] == '1')
                        ones2++;
                    cur[i]= cur[i] == '1'?'0':'1';
                    if(((i+1)%cols) != 0)
                        cur[i+1] = cur[i+1] == '1'?'0':'1';
                    if(((i)%cols) != 0)
                        cur[i-1] = cur[i-1] == '1' ?'0':'1';
                    if(i>=cols)
                        cur[i-cols] = cur[i-cols] == '1'?'0':'1';
                    if((i+cols) < (cols*rows))
                        cur[i+cols] = cur[i+cols] == '1'?'0':'1';
                    if(mp.count(cur)== 0)
                    {
                        q.push(cur);
                    }

                    cur[i]= cur[i] == '1'?'0':'1';
                    if(((i+1)%cols) != 0)
                        cur[i+1] = cur[i+1] == '1'?'0':'1';
                    if(((i)%cols) != 0)
                        cur[i-1] = cur[i-1] == '1' ?'0':'1';
                    if(i>=cols)
                        cur[i-cols] = cur[i-cols] == '1'?'0':'1';
                    if((i+cols) < (cols*rows))
                        cur[i+cols] = cur[i+cols] == '1'?'0':'1';
                }
                if(ones2 ==0)
                    return level;
            }
            level++;
        }

        return -1; 
        
    }
};