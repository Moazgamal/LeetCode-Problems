class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {

        int x = floor(maxWeight/w);
        if(n*n*w >= x*w)
        {
            return x;
        }
        return n*n;
        
        
    }
};