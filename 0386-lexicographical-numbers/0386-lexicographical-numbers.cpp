class Solution {
    void fn(int num, vector<int> &res, int &n)
    {
       res.push_back(num);
       num *= 10;
       if(num<=n)
       {
            for(int i = 0 ; i<=9; i++)
            {
                if(num+i<=n)
                    fn(num+i, res, n);
            }
       }
    }
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for(int i = 1; i<= min(n,9); i++)
        {
            fn(i, res,n);
        }
        return res; 
        
    }
};