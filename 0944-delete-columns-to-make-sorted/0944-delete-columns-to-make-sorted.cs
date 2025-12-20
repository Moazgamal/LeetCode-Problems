public class Solution {
    public int MinDeletionSize(string[] strs) {

        int deletedColumns = 0; 
        int szCol = strs[0].Length;
        int szRow = strs.Length;
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
}