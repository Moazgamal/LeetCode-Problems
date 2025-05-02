class Solution {
public:
    string pushDominoes(string dominoes) {
        string ans = "";
        char prev = '$';
        for(int i = 0; i< dominoes.size(); )
        {
            if(dominoes[i]=='L' || dominoes[i]=='R')
            {
                ans.push_back(dominoes[i]);
                prev = dominoes[i];
                i++;
            }
            else
            {
                if(prev == '$')
                {
                    int cnt = 0; 
                    while(i<dominoes.size() && dominoes[i]=='.')
                    {
                        cnt++;
                        i++;
                    }
                    if(i<dominoes.size())
                    {
                        if(dominoes[i] == 'L')
                            ans.append(cnt, 'L');
                        else
                            ans.append(cnt, '.');
                    }
                    else
                        ans.append(cnt, '.');
                    
                }
                else
                {
                    int cnt = 0; 
                    while(i<dominoes.size() && dominoes[i]=='.')
                    {
                        cnt++;
                        i++;
                    }
                    if(i== dominoes.size())
                    {
                        if(prev == 'R')
                            ans.append(cnt, 'R');
                        else
                            ans.append(cnt, '.');
                    }
                    else
                    {
                        if(prev== 'R')
                        {
                            if(dominoes[i] == 'R')
                                ans.append(cnt, 'R');
                            else
                            {
                                if(cnt %2 == 0)
                                {
                                    ans.append(cnt/2, 'R');
                                    ans.append(cnt/2, 'L');
                                }
                                else
                                {
                                    ans.append(cnt/2, 'R');
                                    ans.push_back('.');
                                    ans.append(cnt/2, 'L');
                                }
                            }
                        }
                        else
                        {
                            if(prev == 'L')
                            {
                                if(dominoes[i] == 'L')
                                    ans.append(cnt, 'L');
                                else
                                {
                                    ans.append(cnt, '.');
                                }
                            }
                        }
                    }
                }
            }
        }
        return ans; 
        
    }
};