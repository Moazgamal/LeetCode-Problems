class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        vector<long long> v;
        const int MAXI = 1e9+1;
        long long i = 1;
        for(; i< MAXI; )
        {
            v.push_back(i);
            i*=4;
        }
        v.push_back(MAXI);
        unordered_map<long long ,int> mp;
        int counter = 1; 
        for(int i = 0; i< v.size(); i++)
        {
            mp[v[i]]=counter;
            counter++;
        }
        long long ans = 0; 
        for(int i = 0; i< queries.size(); i++)
        {
            long long left = queries[i][0];
            long long right = queries[i][1];
            long long cnt = 0;
            int first = -1; int second = -1; 
            for(int j = 0; j< v.size(); j++)
            {
                if(v[j] >= right && second == -1)
                {
                    second = j;
                }
                if(v[j] >= left && first == -1)
                {
                    if(v[j] == left)
                        first = j;
                    else
                        first = j-1;
                }
            }
            int k  = first;
            while(k < second)
            {
                long long val = mp[v[k]];
                long long diff = v[k+1]-v[k];
                cnt += (val*diff);
                k++;
            }
            if(right == v[second])
            {
                cnt += mp[v[second]];
            }
            if(left > v[first])
            {
                long long diff = left-v[first];
                cnt -= (diff*mp[v[first]]);
            }
            if(v[second] > right)
            {
                long long diff = v[second]-right;
                diff--;
                cnt -= (diff*mp[v[second-1]]);
            }
            ans += (cnt+1)/2;
        }
        return ans; 
        
    }
};