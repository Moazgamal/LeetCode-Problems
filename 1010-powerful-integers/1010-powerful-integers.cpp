class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_map<int,int>mp;
        vector<int>res;
        for(int i = 1; i<bound; i*=x)
        {
            int sum = i;
            for(int j =1; j< bound; j*=y)
            {
                sum= i+j;
                if(sum <=bound && mp.count(sum)==0)
                {
                    res.push_back(sum);
                    mp[sum]++;
                }
                if(y==1)
                    break;
            }
            if(x==1)
                break;
            
        }return res;
        
    }
};