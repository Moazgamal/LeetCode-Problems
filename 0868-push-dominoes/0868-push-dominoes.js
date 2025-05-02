/**
 * @param {string} dominoes
 * @return {string}
 */
var pushDominoes = function(dominoes) {
    let ans = [];
        let prev = '$';
        for(let i = 0; i< dominoes.length; )
        {
            if(dominoes[i]=='L' || dominoes[i]=='R')
            {
                ans += dominoes[i].repeat(1);
                prev = dominoes[i];
                i++;
            }
            else
            {
                if(prev == '$')
                {
                    let cnt = 0; 
                    while(i<dominoes.length && dominoes[i]=='.')
                    {
                        cnt++;
                        i++;
                    }
                    if(i<dominoes.length)
                    {
                        if(dominoes[i] == 'L')
                            ans+= dominoes[i].repeat(cnt);
                        else
                            ans+= '.'.repeat(cnt);
                    }
                    else
                        ans+= '.'.repeat(cnt);
                }
                else
                {
                    let cnt = 0; 
                    while(i<dominoes.length && dominoes[i]=='.')
                    {
                        cnt++;
                        i++;
                    }
                    if(i== dominoes.length)
                    {
                        if(prev == 'R')
                            ans += prev.repeat(cnt);
                        else
                            ans+= '.'.repeat(cnt);
                    }
                    else
                    {
                        if(prev== 'R')
                        {
                            if(dominoes[i] == 'R')
                                ans += dominoes[i].repeat(cnt);
                            else
                            {
                                if(cnt %2 == 0)
                                {
                                    ans+= 'R'.repeat(cnt/2);
                                    ans += 'L'.repeat(cnt/2);
                                }
                                else
                                {
                                    ans += 'R'.repeat(cnt/2);
                                    ans+= '.'.repeat(1);
                                    ans+= 'L'.repeat(cnt/2);
                                }
                            }
                        }
                        else
                        {
                            if(prev == 'L')
                            {
                                if(dominoes[i] == 'L')
                                    ans += dominoes[i].repeat(cnt);
                                else
                                    ans += '.'.repeat(cnt);
                            }
                        }
                    }
                }
            }
        }
        return ans;
    
};