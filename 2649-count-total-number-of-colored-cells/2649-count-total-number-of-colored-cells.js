/**
 * @param {number} n
 * @return {number}
 */
var coloredCells = function(n) {
        let ans = 1;
        let factor = 4;
        factor = n-1;
        factor = 4*(factor*(factor+1)/2);
        ans+=factor;
        return ans;
};