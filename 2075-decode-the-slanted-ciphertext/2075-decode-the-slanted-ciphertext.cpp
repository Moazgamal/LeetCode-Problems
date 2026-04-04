class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        int cols  = encodedText.size()/rows;
       
        vector<vector<char>>v(rows, vector<char>(cols,' '));
        int i = 0; 
        for(int r = 0; r< rows; r++)
        {
            for(int c = 0; c< cols; c++)
            {
                v[r][c] = encodedText[i++];
            }
        }
        string ans ="";
        for(int c = 0; c< cols; c++)
        {
            int curC = c; int curR= 0; 
            string str = "";
            while(curC < cols && curR < rows)
            {
                str.push_back(v[curR][curC]); 
                curR++; curC++;
            }
            ans += str;
            
        }
        int j = ans.size()-1;
        while(j>=0 && ans[j] == ' ')
            j--;
            
        return ans.substr(0, j+1); 
    }
};