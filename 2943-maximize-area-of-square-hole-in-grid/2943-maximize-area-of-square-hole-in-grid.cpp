class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());
        int maxi1 = 1; 
        int maxi2 = 1; 
        int i = 0; int sz1 = (int)hBars.size();
        int sz2 = (int)vBars.size();
        while(i< sz1)
        {
            int firstPile = 0; 

            if(hBars[i] == 1)
                firstPile = 1; 
            else
                firstPile = hBars[i]-1;

            int j = i;

            while(j+1 < sz1 && hBars[j+1] == hBars[j]+1)
                j++;

            int secondPile = 0; 

            if(hBars[j] == 2+n)
                secondPile = hBars[j];
            else
                secondPile = hBars[j]+1;

            maxi1 = max(maxi1, secondPile-firstPile);
            i= j+1;
        }
        i = 0; 
        while(i < sz2)
        {
            int firstPile = 0; 

            if(vBars[i] == 1)
                firstPile = 1; 
            else
                firstPile = vBars[i]-1;

            int j = i;

            while(j+1<sz2 && vBars[j+1] == vBars[j]+1)
                j++;

            int secondPile = 0; 

            if(vBars[j] == 2+m)
                secondPile = vBars[j];
            else
                secondPile = vBars[j]+1;

            maxi2 = max(maxi2, secondPile-firstPile);
            i= j+1;
        }
        return min(maxi1,maxi2)*min(maxi1,maxi2);
    }
};