public class Solution {
    public int[] CorpFlightBookings(int[][] bookings, int n) {
        
        int acc = 0; 
        int[]x= new int[n+2];
        for(int i = 0; i< bookings.Length; i++)
        {
            int s = bookings[i][0];
            int e = bookings[i][1];
            int val = bookings[i][2];
            x[s]+= val;
            x[e+1]-=val;
        }int[]res = new int[n];
        for(int i= 0; i<n; i++)
        {
            acc += x[i+1];
            res[i] = acc;
        }return res; 
    }
}