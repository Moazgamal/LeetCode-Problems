class Solution {
public:
    int longestString(int x, int y, int z) {
        
        if(y>x)
        {
            return 2*(x+ (x+1) +z);
        }
        else if(x>y)
        {
            return 2*(y+ (y+1)+z);
        }
        return 2*(y+x+z);

    }
};