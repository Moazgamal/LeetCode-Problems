class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int deletedColumns = 0; 
        int szCol = (int)strs[0].size();
        int szRow = (int)strs.size();
        int i  = 0; 
        while(i< szCol)
        {
            char last = strs[0][i];
            int j = 1; 
            while(j< szRow)
            {
                if(strs[j][i] < last)
                {
                    deletedColumns++;
                    break;
                }
                last = strs[j][i];
                j++;
            }
            i++;
        }
        return deletedColumns;
    }
};