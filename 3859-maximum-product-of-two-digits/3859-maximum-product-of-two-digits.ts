function maxProduct(n: number): number {
    let ans = 0; 
        let s = n.toString();
        for(let i = 0; i< s.length; i++)
            {
                for(let j = i+1; j< s.length; j++)
                    {
                        ans = Math.max(ans, (+s[i])*(+s[j]));
                    }
            }
        return ans;
    
};