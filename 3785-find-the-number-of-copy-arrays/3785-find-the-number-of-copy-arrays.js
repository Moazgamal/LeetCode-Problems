/**
 * @param {number[]} original
 * @param {number[][]} bounds
 * @return {number}
 */
var countArrays = function(original, bounds) {
    if(original.length ==1)
        {
            return bounds[0][1]-bounds[0][0]+1;
        }
        let ans = Number.MAX_SAFE_INTEGER;
        let mini = -1;
        let maxi = -1;
        for(let i = 1; i< original.length; i++)
        {
            let diff = original[i]-original[i-1];
            let x = bounds[i][0];
            let y = bounds[i][1];
            if(mini == -1 && maxi == -1)
            {
                mini =  bounds[i-1][0]+diff;
                maxi = bounds[i-1][1]+diff;
            }
            else
            {
                mini= mini+diff;
                maxi = maxi+diff;
            }
            // long long w = abs(x-mini) + abs(y-maxi);
            // long long sum = ((y-x+1) + (maxi-mini+1));
            // sum-= w; sum/=2;
            mini = Math.max(mini, x);
            maxi = Math.min(maxi, y);
            ans = Math.min(ans, maxi-mini+1);
        }
        return ans <= 0 ? 0 : ans; 
};