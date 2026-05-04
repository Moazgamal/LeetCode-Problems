class Solution {
    void shift(int r, int c, vector<vector<int>>&m, int rS, int cS, int cnt)
    {
        int temp = m[r][c];
        int temp2 = m[r][c];
        int movingR = rS;
        int movingC = cS;
        char dir = 'R';
        while(true)
        {
            if(dir == 'R')
            {
                if(movingC+1 < m.size()-cnt)
                {
                    movingC++;
                    temp2 = m[movingR][movingC];
                    m[movingR][movingC] = temp;
                    temp = temp2;
                }
                else
                {
                    dir = 'D';
                    movingR++;
                    temp2 = m[movingR][movingC];
                    m[movingR][movingC] = temp;
                    temp = temp2;
                }
            }
            else if(dir == 'D')
            {
                if(movingR+1 < m.size()-cnt)
                {
                    movingR++;
                    temp2 = m[movingR][movingC];
                    m[movingR][movingC] = temp;
                    temp = temp2;
                }
                else
                {
                    dir = 'L';
                    movingC--;
                    temp2 = m[movingR][movingC];
                    m[movingR][movingC] = temp;
                    temp = temp2;
                }
            }
            else if(dir == 'L')
            {
                if(movingC-1>=cnt)
                {
                    movingC--;
                    temp2 = m[movingR][movingC];
                    m[movingR][movingC] = temp;
                    temp = temp2;
                }
                else
                {
                    dir= 'U';
                    movingR--;
                    temp2 = m[movingR][movingC];
                    m[movingR][movingC] = temp;
                    temp = temp2;
                }
            }
            else
            {
                if(movingR-1>=cnt)
                {
                    movingR--;
                    temp2 = m[movingR][movingC];
                    m[movingR][movingC] = temp;
                    temp = temp2;
                }
                else
                    return ; 
            }
        }
    }
public:
    void rotate(vector<vector<int>>& matrix) {
        int cnt = 0; 
        int sz = matrix.size();
        if(sz == 1)
            return;
        int h = sz-1;
        for(int i = 0; i< sz/2; i++, cnt++, h-=2)
            for(int j = 0; j< h; j++)
                shift(i,i, matrix, i, i, cnt);

    }
};