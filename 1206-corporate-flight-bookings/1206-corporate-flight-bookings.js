/**
 * @param {number[][]} bookings
 * @param {number} n
 * @return {number[]}
 */
var corpFlightBookings = function(bookings, n) {

    let acc = 0; 
        let x= new Array(n+2).fill(0);
        for(let i = 0; i< bookings.length; i++)
        {
            let s = bookings[i][0];
            let e = bookings[i][1];
            let val = bookings[i][2];
            x[s]+= val;
            x[e+1]-=val;
        }let res = new Array(n).fill(0);
        for(let i= 0; i<n; i++)
        {
            acc += x[i+1];
            res[i] = acc;
        }return res; 
    
};