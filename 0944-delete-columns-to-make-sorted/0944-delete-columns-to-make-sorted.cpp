class Solution {
public:
    int minDeletionSize(vector<string>& strs) {

        int deletedColumns = 0; 
        for(int i = 0; i< strs[0].size(); i++)
        {
            char last = strs[0][i];
            for(int j = 1; j< strs.size(); j++)
            {
                if(strs[j][i] < last)
                {
                    deletedColumns++;
                    break;
                }
                last = strs[j][i];
            }
        }return deletedColumns;
        
    }
};