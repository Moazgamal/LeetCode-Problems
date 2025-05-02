public class Solution {
    public string PushDominoes(string dominoes) {
    StringBuilder ans = new StringBuilder();
        char prev = '$';
        for(int i = 0; i< dominoes.Length; )
        {
            if(dominoes[i]=='L' || dominoes[i]=='R')
            {
                ans.Append(dominoes[i],1);
                prev = dominoes[i];
                i++;
            }
            else
            {
                if(prev == '$')
                {
                    int cnt = 0; 
                    while(i<dominoes.Length && dominoes[i]=='.')
                    {
                        cnt++;
                        i++;
                    }
                    if(i<dominoes.Length)
                    {
                        if(dominoes[i] == 'L')
                            ans.Append('L', cnt);
                        else
                            ans.Append('.', cnt);
                    }
                    else
                        ans.Append('.', cnt);
                }
                else
                {
                    int cnt = 0; 
                    while(i<dominoes.Length && dominoes[i]=='.')
                    {
                        cnt++;
                        i++;
                    }
                    if(i== dominoes.Length)
                    {
                        if(prev == 'R')
                            ans.Append('R', cnt);
                        else
                            ans.Append('.', cnt);
                    }
                    else
                    {
                        if(prev== 'R')
                        {
                            if(dominoes[i] == 'R')
                                ans.Append('R', cnt);
                            else
                            {
                                if(cnt %2 == 0)
                                {
                                    ans.Append('R', cnt/2);
                                    ans.Append('L', cnt/2);
                                }
                                else
                                {
                                    ans.Append('R', cnt/2);
                                    ans.Append('.', 1);
                                    ans.Append('L', cnt/2);
                                }
                            }
                        }
                        else
                        {
                            if(prev == 'L')
                            {
                                if(dominoes[i] == 'L')
                                    ans.Append('L', cnt);
                                else
                                    ans.Append('.', cnt);
                            }
                        }
                    }
                }
            }
        }
        return ans.ToString();
        
    }
}