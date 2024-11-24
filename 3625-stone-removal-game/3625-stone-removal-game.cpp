class Solution {
public:
    bool canAliceWin(int n) {

    if(n<10)
        return false;
    n-=10;
    int x = 9;
    bool a = false;
    while(n>0)
        {
            if(a == true)
            {
                if(n-x>=0)
                {
                    n-=x;
                    a=false;
                    x--;
                }
                else
                    return false;
            }
            else
            {
                if(n-x>=0)
                {
                    n-=x;
                    a=true;
                    x--;
                }
                else
                    return true;
            }
        }
        if(a==true)
            return false;
        return true;
        
        
    }
};