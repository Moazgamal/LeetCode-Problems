function minDeletionSize(strs: string[]): number {

    var deletedColumns = 0; 
        var szCol = strs[0].length;
        var szRow = strs.length;
        var i  = 0; 
        while(i< szCol)
        {
            var last = strs[0][i];
            var j = 1; 
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