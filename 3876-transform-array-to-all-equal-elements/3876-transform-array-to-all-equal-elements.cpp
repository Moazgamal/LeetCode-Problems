class Solution {
public:
    bool canMakeEqual(vector<int>& nums, int k) {
        vector<int> x = nums;
        int _k= k;
        bool g = true;
        for(int i =0; i< x.size()-1; i++)
            {
                if(x[i] !=1)
                {
                    if(_k>0)
                    {
                        x[i+1]= -1*x[i+1];
                        _k--;
                    }
                    else
                    {
                        g = false;
                        break;
                    }
                }
            }
        if(x[x.size()-1] == 1)
        {
            if(g)
                return true;
        }
        _k = k; 
        g = true;
        vector<int> y = nums;
        for(int i =0; i< y.size()-1; i++)
            {
                if(y[i] != -1)
                {
                    if(_k>0)
                    {
                        y[i+1]= -1*y[i+1];
                        _k--;
                    }
                    else
                    {
                        g = false;
                        break;
                    }
                }
            }
        if(y[y.size()-1] ==-1)
        {
            if(g)
                return true;
        }
        return false;
        
        
        
        
    }
};