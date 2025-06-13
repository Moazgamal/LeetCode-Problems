class Solution {
public:
    int maxDifference(string s, int k) {
        int ans = INT_MIN;

        for(int i = 0; i<= 4; i++)
        {
            for(int j = 0; j<= 4; j++)
            {
                if(i== j)
                    continue;
                char c1 = i+'0';
                char c2 = j +'0';
                vector<int> prefixA(s.size(),0);
                vector<int> prefixB(s.size(),0);
                int p1 = 0; int p2 = 0;
                for(int x = 0; x< s.size(); x++)
                {
                    if(s[x] == c1)
                        p1++;
                    if(s[x] == c2)
                        p2++;
                    prefixA[x] = p1;
                    prefixB[x] = p2;
                }
                vector<int> minval(4,INT_MAX);
                vector<int> idx(4,-1);
                int left = 0; 
                int right = 0;
                while(right<s.size())
                {
                    if((right -left)+1 ==k)
                    {
                        if(prefixA[right]%2 != 0 && prefixB[right]%2 ==0 && prefixA[right]!=0 && 
                        prefixB[right]!=0)
                            ans = max(ans, prefixA[right]-prefixB[right]);
                        right++;
                        continue;
                    }
                    else if(right -left +1 <k)
                    {
                        right++;
                    }
                    else
                    {
                        int val = prefixA[left]-prefixB[left];
                        if(prefixA[left]%2==0 )
                        {
                            if(prefixB[left]%2==0 )
                            {
                                if(minval[0] > val)
                               {
                                    minval[0] =min(minval[0], val);
                                    idx[0] = left;
                               }
                            }
                            else
                            {
                                 if(minval[1] > val)
                               {
                                    minval[1] =min(minval[1], val);
                                    idx[1] = left;
                               }
                            }

                        }
                        else
                        {
                            if(prefixB[left]%2!=0)
                            {

                               if(minval[2] > val)
                               {
                                    minval[2] =min(minval[2], val);
                                    idx[2] = left;
                               }
                            }
                            else
                            {

                                if(minval[3] > val)
                               {
                                    minval[3] =min(minval[3], val);
                                    idx[3] = left;
                               }
                            }
                        }
                        left++;
                        int val2 = prefixA[right] - prefixB[right];
                        if(prefixA[right]%2 ==0)
                        {
                            if(prefixB[right] %2 ==0)
                            {
                                if(minval[3] != INT_MAX)
                                {
                                    if(prefixA[idx[3]] != prefixA[right] 
                                    && prefixB[idx[3]] != prefixB[right]&&
                                    prefixA[right]!=0 && 
                                    prefixB[right]!=0)
                                    {
                                        ans = max(ans, val2-minval[3]);
                                    }
                                }
                            }
                            else
                            {
                                if(minval[2] != INT_MAX)
                                {
                                    if(prefixA[idx[2]] != prefixA[right] 
                                    && prefixB[idx[2]] != prefixB[right]&&
                                    prefixA[right]!=0 && 
                                    prefixB[right]!=0)
                                    {
                                        ans = max(ans, val2-minval[2]);
                                    }
                                }
                            }
                        }
                        else
                        {
                            if(prefixB[right]%2 !=0)
                            {
                                if(minval[1] != INT_MAX)
                                {
                                    if(prefixA[idx[1]] != prefixA[right] 
                                    && prefixB[idx[1]] != prefixB[right]&&
                                    prefixA[right]!=0 && 
                                    prefixB[right]!=0)
                                    {
                                        ans = max(ans, val2-minval[1]);
                                    }
                                }
                            }
                            else
                            {
                                if(prefixA[right]!=0 && prefixB[right] !=0)
                                    ans = max(ans, val2);
                                if(minval[0] != INT_MAX)
                                {
                                    if(prefixA[idx[0]] != prefixA[right] 
                                    && prefixB[idx[0]] != prefixB[right]&&
                                    prefixA[right]!=0 && 
                                    prefixB[right]!=0)
                                    {
                                        ans = max(ans, val2-minval[0]);
                                    }
                                }
                            }
                        }
                        right++;
                    }
                }
            }
        }
        return ans; 
        
    }
};