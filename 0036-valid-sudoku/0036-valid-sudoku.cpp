class Solution {
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        unordered_map<int, unordered_set<char> > row;
        unordered_map<int, unordered_set<char> > col;
        unordered_map<int, unordered_set<char> > box;

        for(int r = 0; r < board.size(); r++)
        {
            for(int c = 0; c< board[0].size(); c++)
            {
                if(board[r][c] == '.')
                    continue;
                if(row[r].find(board[r][c]) != row[r].end())
                    return false; 
                row[r].insert(board[r][c]);
                if(col[c].find(board[r][c]) != col[c].end())
                    return false; 
                col[c].insert(board[r][c]);
                int b = (floor(r/3))*3 + (floor(c/3));
                if(box[b].find(board[r][c]) != box[b].end())
                    return false;
                box[b].insert(board[r][c]);
            }
        }
        
        return true;
        
    }
};