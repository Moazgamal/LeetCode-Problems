class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        long long maxi = -1;
        for(int i = 0; i< groups.size(); i++)
        {
            maxi=max((long long)groups[i], maxi);
        }
        vector<long long> v (1e5+1,-1);
        long long x = 1e5 + 5;
       
        for(int i = 0; i< elements.size(); i++)
        {
            int val = elements[i];
            if(v[val]==-1)
                v[val]= i;
            else
                continue;
            for(long long j = val; (j)<=maxi; j+=val)
            {
                if(v[j] == -1)
                {
                    v[j] = i;
                }
            }
        }
        vector<int> res(groups.size(),-1);
        for(int i = 0; i< groups.size(); i++)
        {
            res[i] = v[groups[i]];
        }return res;
        
        
        
    }
};