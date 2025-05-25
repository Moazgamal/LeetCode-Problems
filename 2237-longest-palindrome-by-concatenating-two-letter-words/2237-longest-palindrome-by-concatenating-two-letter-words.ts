function longestPalindrome(words: string[]): number {
    let mp = new Map();
        for(let i = 0; i< words.length; i++)
        {
            if(mp.has(words[i]) == true)    
                {
                    let r = mp.get(words[i]);
                    mp.set(words[i], r+1);
                }
            else
                mp.set(words[i], 1);
        }
        let evens = 0; 
        let w = 0;
        for(let [key, value] of mp)
        {
            let str = key;
            let reversed = str.split("").reverse().join("");
            
            if(mp.has(reversed) == true && str[0] != str[1])
            {
                let f = mp.get(reversed);
                f = Math.min(f, value);
                evens += (4*f);
                mp.set(reversed,0);
            }
            else if(str[0] == str[1])
            {
                let f = value;
                if(f%2 ==0)
                    evens += 2*f;
                else
                {
                    evens += (2*(f-1));
                    w = 1;
                }
            }
        }
        let t = evens + w*2;
        return t ? t : 0;
    
};