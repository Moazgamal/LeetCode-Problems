class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {

        int acc = 0; 
        vector<int>x (n+2,0);
        for(int i = 0; i< bookings.size(); i++)
        {
            int s = bookings[i][0];
            int e = bookings[i][1];
            int val = bookings[i][2];
            x[s]+= val;
            x[e+1]-=val;
        }vector<int>res(n,0);
        for(int i= 0; i<n; i++)
        {
            acc += x[i+1];
            res[i] = acc;
        }return res; 
        
    }
};