function minDeletion(s: string, k: number): number {

    let mp = {};
        for(let i = 0; i< s.length; i++)
            {
                mp[s[i]] = (mp[s[i]] || 0) +1;
            }
        let sz = Object.keys(mp).length;
        if(sz <=k)
            return 0; 
       
        let v = [];
        for(let [key, value] of Object.entries(mp))
            {
                v.push(value);
            }
        v.sort((a, b) => a - b);
        let ops = 0; 
        let sz2 = v.length;
        for(let i = 0; i< sz2; i++)
            {
                ops += v[i];
                sz--;
                if(sz ==k)
                    return ops;
            }
        return ops;
    
};