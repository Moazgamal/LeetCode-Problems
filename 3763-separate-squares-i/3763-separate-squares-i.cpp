class Solution {
    bool static compare(vector<int> &a, vector<int>&b)
    {
        return a[1] < b[1];
    }
    double fn(double mid, vector<vector<int>>& squares)
    {
        double area = 0; 
        for(int i = 0; i< squares.size(); i++)
        {
            if((double)squares[i][1] + (double)squares[i][2] <= mid)
               area+=((double)squares[i][2] * (double)squares[i][2]);
            else if((double)squares[i][1] < mid)
            {
                double h = mid - (double)squares[i][1];
                area+=(h*(double)squares[i][2]);
            }
        }
        return area;
    }
public:
    double separateSquares(vector<vector<int>>& squares) {
        sort(squares.begin(), squares.end(), compare);
        double mini = 0;
        double maxi = INT_MAX;
        double totalArea =0; 
        for(int i = 0; i< squares.size(); i++)
        {
            totalArea += ((double)squares[i][2] * (double)squares[i][2]);
        }
        totalArea/=2;
        double mid = 0 ;
        double pos = 0; 
        while(maxi-mini>1e-5)
        {
            mid= mini + (maxi-mini)/2;
            double area = fn(mid, squares);
            if( area >= totalArea)
            {
                pos = mid;
                maxi = mid;
            }
            else
            {
                mini= mid;
            }
        }
        return maxi;
        
    }
};