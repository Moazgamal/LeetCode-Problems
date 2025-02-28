/**
 * @param {string} s
 * @return {boolean}
 */
var hasSameDigits = function(s) {
     
        while(true)
            {
                let str = [];
                for(let i = 0; i< s.length-1; i++)
                    {
                        let x = ((+s[i]) + (+s[i+1]))%10;
                        str.push(x.toString());
                    }
                if(str.length==2)
                {
                    if(str[0] == str[1])
                        return true;
                    return false;
                }
                if(str.length<2)
                    return false;
                s = str;
                continue;
            }
        return false;
};