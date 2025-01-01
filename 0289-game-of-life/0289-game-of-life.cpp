class Solution {
    bool isvalid(int r, int c , vector<vector<int>>&board)
    {
        if(r<0 || r>=board.size() || c<0 || c>=board[0].size())
            return false;
        return true;
    }
public:
    void gameOfLife(vector<vector<int>>& board) {

        int dr[8] = {0,0,-1,1, -1, 1,-1,1};
        int dc[8]= {-1,1,0,0, 1,1,-1,-1};
        for(int r = 0; r< board.size(); r++)
        {
            for(int c = 0; c< board[0].size(); c++)
            {
                if(board[r][c] == 0)
                {
                    int cnt = 0; 
                    for(int d = 0; d< 8; d++)
                    {
                        int row = r+dr[d]; int col = c +dc[d];
                        if(isvalid(row, col, board) && (board[row][col] == 1 || board[row][col] ==3))
                        {
                            cnt++;
                        }
                    }
                    if(cnt == 3)
                        board[r][c] =2;
                }
                else if(board[r][c] == 1)
                {
                    int cnt = 0; 
                    for(int d = 0; d< 8; d++)
                    {
                        int row = r+dr[d]; int col = c +dc[d];
                        if(isvalid(row, col, board) && (board[row][col] == 1 || board[row][col] ==3))
                        {
                            cnt++;
                        }
                    }
                    if(cnt > 3 || cnt<2)
                        board[r][c] =3;
                
                }
            }
        }
        for(int r = 0; r< board.size() ; r++)
        {
            for(int c = 0; c< board[0].size(); c++)
            {
                if(board[r][c] == 3)
                {
                    board[r][c] = 0; 
                }
                if(board[r][c] == 2)
                    board[r][c] = 1;
            }
        }
        
    }
};