/**
 * @param {number} n
 * @return {number[][]}
 */
var specialGrid = function(n) {

    let N = n;
        let sz = 1<<N;
         if(N ==0)
            return Array.from({ length: sz }, () => Array(sz).fill(0));
        const ans = Array.from({ length: sz }, () => Array(sz).fill(0));
       
         let cnt = 0; 
         build(0, sz-1, sz);
        function build(r, cmax, N){
            if(N == 2)
            {
                ans[r][cmax] = cnt++;
                ans[r+1][cmax] = cnt++;
                ans[r+1][cmax-1] = cnt++;
                ans[r][cmax-1] = cnt++;
                return ;
            }
            let x = N/2;
            for(let i = 0; i< 4; i++)
            {
                build(r, cmax, x);
                if(i== 0)
                    r+= x;
                if(i==1)
                    cmax -= x;
                if(i==2)
                    r -= x;
            }
        };

        return ans;


    
};