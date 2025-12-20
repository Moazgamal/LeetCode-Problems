/**
 * @param {string[]} strs
 * @return {number}
 */
var minDeletionSize = function(strs) {

    let deletedColumns = 0; 
        let szCol = strs[0].length;
        let szRow = strs.length;
        let i  = 0; 
        while(i< szCol)
        {
            let last = strs[0][i];
            let j = 1; 
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
    
};