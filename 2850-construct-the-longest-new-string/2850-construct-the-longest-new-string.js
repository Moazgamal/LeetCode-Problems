/**
 * @param {number} x
 * @param {number} y
 * @param {number} z
 * @return {number}
 */
var longestString = function(x, y, z) {
    if(y>x)
        {
            return 2*(x+ (x+1) +z);
        }
        else if(x>y)
        {
            return 2*(y+ (y+1)+z);
        }
        return 2*(y+x+z);
    
};