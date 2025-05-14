/**
 * @param {string} s
 * @return {number}
 */
var maxFreqSum = function(s) {

    let mp1 = {};
        let mp2 = {};
        let freq1 = 0; let freq2 = 0; 
        
        for(let i = 0; i< s.length; i++)
            {
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                {
                    
                        mp1[s[i]] = (mp1[s[i]] || 0)+1; 
                    
                    freq1 = Math.max(freq1, mp1[s[i]]);
                }
                else
                {
                    
                        mp2[s[i]] = (mp2[s[i]] || 0)+1;
                   
                    freq2 = Math.max(freq2, mp2[s[i]]);
                }
            }
        return freq1 + freq2;
    
};