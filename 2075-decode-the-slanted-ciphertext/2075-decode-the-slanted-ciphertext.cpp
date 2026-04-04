class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        int cols  = (int)encodedText.size()/rows;
        string ans ="";
        int curPos = 0; 
        int curR = 0; 
        int total = rows*cols;
        int i = 0; 
        while(curPos < cols)
        {
            while(curPos < total)
            {
                ans.push_back(encodedText[curPos]);
                curPos = curPos+cols+1;
            }
            i++;
            curPos = i; 
        }
        int j = ans.size()-1;
        while(j>=0 && ans[j] == ' ')
            j--;
        return ans.substr(0, j+1); 
    }
};