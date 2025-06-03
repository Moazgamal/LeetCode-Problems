class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()==1)
            return 1; 
        vector<int> ans(ratings.size(),-1);

        vector<pair<int,int>>pq;

        for(int i = 0; i< ratings.size(); i++)
        {
            pq.push_back({ratings[i],i});
        }
        sort(pq.begin(), pq.end());
        int h = 0; 
        while(h< pq.size())
        {
            auto cur = pq[h++];
            if(ans[cur.second] != -1)
                continue;
            int before = cur.second-1;
            int after = cur.second+1;

            if(before<0)
            {
                if(ratings[after]< ratings[cur.second])
                {
                    ans[cur.second] = ans[after]+1;
                }
                else if(ratings[after] == ratings[cur.second])
                {
                    int j = cur.second;
                    int i = cur.second;
                    while(j<ans.size() && ratings[j] == ratings[i])
                    {
                        j++;
                    }
                    if(j==ans.size())
                    {
                        while(i <j)
                        {
                            ans[i] = 1;i++;
                        }
                    }
                    else if(ratings[j] > ratings[i])
                    {
                        while(i <j)
                        {
                            ans[i] = 1;i++;
                        }
                    }
                    else
                    {
                        int r = ans[j];
                        while(i <j)
                        {
                            ans[i] = 1;
                            i++;
                        }
                        ans[i-1]= r+1;
                    }
                }
                else
                {
                    ans[cur.second] = 1; 
                }
            }
            else if(after == ans.size())
            {
                if(ratings[before]< ratings[cur.second])
                {
                    ans[cur.second] = ans[before]+1;
                }
                else
                {
                    ans[cur.second] = 1; 
                }
            }
            else
            {
                if(ratings[before] > ratings[cur.second] 
                && ratings[after] < ratings[cur.second])
                {
                    ans[cur.second] = ans[after]+1;
                }
                else if(ratings[before]> ratings[cur.second]&&
                ratings[after] > ratings[cur.second])
                {
                    ans[cur.second] = 1; 
                }
                else if(ratings[before]< ratings[cur.second]&&
                ratings[after] < ratings[cur.second])
                {
                    ans[cur.second] = max(ans[before] , ans[after])+1;
                }
                else if(ratings[before]< ratings[cur.second] &&
                ratings[after] > ratings[cur.second])
                {
                    ans[cur.second] = ans[before]+1; 
                }
                else if(ratings[before] > ratings[cur.second] &&
                ratings[after] == ratings[cur.second])
                {
                    int j = cur.second;
                    int i = cur.second;
                    while(j<ans.size() && ratings[j] == ratings[i])
                    {
                        j++;
                    }
                    if(j==ans.size())
                    {
                        while(i <j)
                        {
                            ans[i] = 1;i++;
                        }
                    }
                    else if(ratings[j] > ratings[i])
                    {
                        while(i <j)
                        {
                            ans[i] = 1;i++;
                        }
                    }
                    else
                    {
                        int r = ans[j];
                        while(i <j)
                        {
                            ans[i] = 1;
                            i++;
                        }
                        ans[i-1]= r+1;
                    }
                }
                else if(ratings[before] < ratings[cur.second] &&
                ratings[after] == ratings[cur.second])
                {
                    int j = cur.second;
                    int i = cur.second;
                    int first = ans[before];
                    while(j<ans.size() && ratings[j] == ratings[i])
                    {
                        j++;
                    }
                    if(j==ans.size())
                    {
                        int u = i; 
                        while(i <j)
                        {
                            ans[i] = 1;i++;
                        }
                        ans[u] = first+1;
                    }
                    else if(ratings[j] > ratings[i])
                    {
                        int u = i; 
                        while(i <j)
                        {
                            ans[i] = 1;i++;
                        }
                        ans[u] = first+1;
                    }
                    else
                    {
                        int r = ans[j];
                        int u = i;
                        
                        while(i <j)
                        {
                            ans[i] = 1;
                            i++;
                        }
                        ans[u] = ans[u-1]+1;
                        ans[i-1]= ans[i]+1;
                       
                    }
                }
            }
        }
        int sum = 0; 
        for(int i = 0; i< ans.size(); i++)
        {
            sum+= ans[i];
        }
        return sum; 
        
    }
};