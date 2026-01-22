class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {

        int totalArea = 0; 
        totalArea += ((ax2-ax1)*(ay2-ay1));
        totalArea += ((bx2-bx1)*(by2-by1));
        if(ax1 <= bx1)
        {
            if(by1 < ay2 && by2 > ay1
            && bx1 < ax2)
            {
                int dim1 = min(ax2,bx2) - bx1;
                int dim2 = min(ay2,by2)-max(by1,ay1);
                totalArea -= (dim1*dim2);
            }
        }
        else
        {
            if(ay1 < by2 && ay2 > by1
            && ax1 < bx2)
            {
                int dim1 = min(bx2,ax2) - ax1;
                int dim2 = min(by2,ay2)-max(ay1,by1);
                totalArea -= (dim1*dim2);
            }
        }
        return totalArea;
    }
};