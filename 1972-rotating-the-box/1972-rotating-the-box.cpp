class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box[0].size();
        int cols = box.size();
        vector<vector<char>> result(rows, vector<char>(cols,'.'));
        for(int r=0; r< cols; r++)
        {
            int cnt = 0; 
            for(int c = 0; c<rows; c++)
            {
                if(box[r][c]=='#')
                    cnt++;
                else if(box[r][c] == '*')
                {
                    result[c][cols-r-1]='*';
                    int j = 1;
                    while(cnt>0)
                    {
                        result[c-j][cols-r-1]= '#';
                        j++; cnt--;
                    }
                }
            }
            int j =1;
            while(cnt >0)
            {
                result[rows-j][cols-r-1]= '#';
                j++; cnt--;
            }
        }return result;
        
    }
};