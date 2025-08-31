class Solution {
    bool backtracking(int r, int c, unordered_map<int, unordered_set<char> >&row, unordered_map<int, unordered_set<char> >&col, unordered_map<int, unordered_set<char> >&box,
    vector<vector<char>>&board)
    {
        if(board[r][c] != '.')
        {
            if(r == board.size()-1 && c == board[0].size()-1)
                return true;
            if(c+1 < board[0].size())
                return backtracking(r, c+1, row, col, box, board);
            return backtracking(r+1, 0, row, col, box, board);
        }
        int b = (floor(r/3))*3 + (floor(c/3));
        for(int i = 1; i<= 9; i++)
        {
            char ch = i+'0'; 
            if(row[r].find(ch) == row[r].end() && col[c].find(ch) == col[c].end()
            && box[b].find(ch) == box[b].end())
            {
                row[r].insert(ch); col[c].insert(ch); box[b].insert(ch);
                board[r][c] = ch;
                if(r == board.size()-1 && c == board[0].size()-1)
                    return true;
                if(c+1 < board[0].size())
                {
                    if(backtracking(r, c+1, row, col, box, board))
                        return true; 
                }
                else
                {
                    if(backtracking(r+1, 0, row, col, box, board))
                        return true; 
                }
                row[r].erase(ch); col[c].erase(ch); box[b].erase(ch);
                board[r][c] = '.';
            } 
        }
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_set<char> > row;
        unordered_map<int, unordered_set<char> > col;
        unordered_map<int, unordered_set<char> > box;

        for(int r = 0; r < board.size(); r++)
        {
            for(int c = 0; c< board[0].size(); c++)
            {
                if(board[r][c] == '.')
                    continue;
                row[r].insert(board[r][c]);
                col[c].insert(board[r][c]);
                int b = (floor(r/3))*3 + (floor(c/3));
                box[b].insert(board[r][c]);
            }
        }
        backtracking(0, 0, row, col, box, board);

        
    }
};





