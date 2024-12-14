class Solution {
    struct Compare {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        if(a.first == b.first)
            return a.second>b.second;
        return a.first < b.first;  
    }
};
public:
    long long continuousSubarrays(vector<int>& nums) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq2;
        pq.push({nums[0],0});
        pq2.push({nums[0],0});
        long long ans= nums.size(); 
        int j = 0; 
        int i = 1;
        for( ;i< nums.size(); i++)
        {
           
            int maxi = pq.top().first;
            int mini = pq2.top().first; 

            if(abs(nums[i]-mini)>=0 && abs(nums[i]-maxi) >=0 && abs(nums[i]-maxi)<=2 && abs(nums[i]-mini)<=2)
            {
                ans += (i-j);
                pq.push({nums[i],i});
                pq2.push({nums[i], i});
                continue;
            }
            if(nums[i] > maxi )
            {
                
                    while(!pq2.empty())
                    {
                        if(pq2.top().second <j)
                        {
                            pq2.pop(); continue;
                        }
                        else
                        {
                            int val = abs(nums[i] - pq2.top().first);
                            if( val>=0 && val<=2)
                            {
                                j= max(j, pq2.top().second);
                                break;
                            }
                            else
                            {
                                j= max(j, pq2.top().second+1);
                                pq2.pop();
                            }
                        }
                    }
                    ans+= (i-j);
                    pq2.push({nums[i],i});
                    pq.push({nums[i],i});
            }
            else if(nums[i] <mini)
            {
                while(!pq.empty())
                    {
                        if(pq.top().second <j)
                        {
                            pq.pop(); continue;
                        }
                        else
                        {
                            int val = abs(pq.top().first - nums[i]);
                            if( val>=0 && val<=2)
                            {
                                j= max(j, pq.top().second);
                                break;
                            }
                            else
                            {
                                j= max(j, pq.top().second+1);
                                pq.pop();
                            }
                        }
                    }
                    ans+= (i-j);
                    pq2.push({nums[i],i});
                    pq.push({nums[i],i});
            }
        }
        return ans;
        
    }
};