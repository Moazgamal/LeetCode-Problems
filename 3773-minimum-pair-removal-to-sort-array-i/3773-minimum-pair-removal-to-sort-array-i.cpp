class Solution {
    bool check(vector<int>&v)
    {
        for(int i = 0; i< v.size()-1; i++)
            {
                if(v[i] <= v[i+1])
                    continue;
                else
                {
                    // cout<<v[i]<<" "<<v[i+1]<<"\n";
                    return false;
                }
            }
        return true;
    }
    void handle(vector<int> &v)
    {
        vector<int> newv ;
        int idx = -1; 
        int sum = INT_MAX;
        for(int i = 0; i< v.size()-1; i++)
            {
                
                    if(v[i]+v[i+1] < sum)
                    {
                        sum = v[i]+v[i+1];
                        idx = i;
                    }
                
            }
        for(int i = 0; i< v.size(); i++)
            {
                if(i == idx)
                {
                    newv.push_back(v[i]+v[i+1]);
                    i++;
                }
                else
                {
                    newv.push_back(v[i]);
                }
            }
        v = newv;
    }
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> v = nums;
        int ans = 0; 
        
                while(check(v) == false)
                {
                    ans++;
                    handle(v);
                }
        return ans;
            
        
    }
};