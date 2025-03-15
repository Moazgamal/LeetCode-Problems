class Spreadsheet {
public:
vector<vector<int>>v;
    Spreadsheet(int rows) {
        vector<vector<int>> x (rows, vector<int>(26,0));
        v=x;
    }
    
    void setCell(string cell, int value) {
        int col = (cell[0]-'A');
        int row = 0; 
        int f = 1; 
        for(int i= cell.size()-1; i>=1 ; i--)
            {
                row += (cell[i]-'0')*f;
                f = f*10;
            }
        row--;
        v[row][col] = value;
        
        
    }
    
    void resetCell(string cell) {
        setCell(cell, 0);
    }
    
    int getValue(string formula) {
        int i = 1; 
        int col1 = -1; 
        int row1 = 0; 
        int num = 0;
        string acc = "";        
        while(formula[i] != '+')
            {
                if(!isdigit(formula[i]))
                {
                    col1 = formula[i]-'A';
                }
                else
                {
                    
                    acc.push_back(formula[i]);
                }
                i++;
            }
        int idx = stoi(acc);
        int x1 = 0; 
        if(col1 != -1)
        {
            x1 = v[idx-1][col1];
        }
        else
        {
            x1 = idx;
        }
        acc="";
        col1 = -1; 
        row1 = 0; 
        num = 0;
        i++;
        // f=1;
        while(i<formula.size())
            {
                if(!isdigit(formula[i]))
                {
                    col1 = formula[i]-'A';
                }
                else
                {
                    acc.push_back(formula[i]);
                }
                i++;
            }
        idx = stoi(acc);
        int x2 = 0; 
        if(col1 != -1)
        {
            x2 = v[idx-1][col1];
        }
        else
        {
            x2 = idx;
        }
        // cout<<x1<<" "<<x2;
        return x1 + x2; 
        
        
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */