/**
 * @param {number} n
 * @return {boolean}
 */
var checkPowersOfThree = function(n) {
    let base = 3;
        let maxi = Math.ceil(Math.log(n) / Math.log(base));  
        return fn(0, n, maxi,0);
    function fn(power,  number,  maxipower,  accsum)
    {
        if(accsum== number)
            return true;
        if(accsum>number)
            return false;
        if(power > maxipower)
            return false;
        let leave = fn(power+1, number, maxipower, accsum);
        if(leave)
            return true;
        let pick = fn(power+1, number, maxipower,Math.pow(3,power)+accsum);
        return pick ;
    }
};