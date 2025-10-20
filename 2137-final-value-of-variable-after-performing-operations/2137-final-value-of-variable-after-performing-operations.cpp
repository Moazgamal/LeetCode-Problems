class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0; int i = 0; int sz = (int)operations.size(); 
        while(i< sz)
        {
            if(operations[i][0] == 'X')
                if(operations[i][1] == '+')
                    x++;
                else
                    x--;
            else if(operations[i][0] == '+')
                x++;
            else
                x--;
            i++;
        }return x; 
        
    }
};