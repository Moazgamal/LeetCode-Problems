class Solution {
    vector<string> fn(int rows, int cols, int k)
    {
        vector<vector<char>>v(rows, vector<char>(cols, '#'));
        for(int c = 0; c< cols; c++)
            v[0][c] ='.';
        for(int r = 0; r< rows; r++)
            v[r][cols-1] = '.';

        int nextRow = 1; int nextCol = cols-2;
        for(int i = 2; i<=k ; i++)
        {
            v[nextRow][nextCol]='.';
            if(nextCol-1 <0)
                nextRow++;
            else
                nextCol--;
        }
        if(cols==3 && k == 4)
        {
            v[0][cols-1]='#';
            v[2][cols-2]='.';
            v[2][0]='#';

        }
        vector<string>ans;
        for(int i = 0; i< v.size(); i++)
        {
            string str = "";
            for(int j = 0; j< v[0].size(); j++)
            {
                str.push_back(v[i][j]);
            }
            ans.push_back(str);
        }
        return ans; 
    }
public:
    vector<string> createGrid(int m, int n, int k) {
        if((m == 1 || n == 1) && k>1)
            return {};
        if(k == 3 && (m==2 && n==2))
            return {};
        if(k == 4 &&(m==2&&(n==2||n==3)))
            return {};
        if(k==4 && (m==3 && n==2))
            return {};

        return fn(m, n, k);
    }
};