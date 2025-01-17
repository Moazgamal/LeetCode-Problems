class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {

        if(derived.size()==1)
            if(derived[0] == 1)
                return false;
            else
                return true;
        vector<int> f(derived.size(), -1);
        if(derived[derived.size()-1] == 1)
        {
            f[f.size()-1] = 0; f[0]=1;
            for(int i = 0; i< f.size()-1; i++)
            {
                int x = derived[i];
                if(x ==1)
                {
                    if(f[i] == 0)
                        f[i+1] = 1;
                    else
                        f[i+1]=0;
                }
                else
                {
                    if(f[i] == 0)
                        f[i+1] = 0;
                    else
                        f[i+1]=1;
                }
            }
            if(f[f.size()-1] ==0 && f[0]==1)
                return true;
            return false;
        }
        else
        {
            f[f.size()-1] = 0; f[0]=0;
           
            for(int i = 0; i< f.size()-1; i++)
            {
                int x = derived[i];
                if(x ==1)
                {
                    if(f[i] == 0)
                        f[i+1] = 1;
                    else
                        f[i+1]=0;
                }
                else
                {
                    if(f[i] == 0)
                        f[i+1] = 0;
                    else
                        f[i+1]=1;
                }
            }
            if(f[f.size()-1] ==0 && f[0]==0)
                return true;
            return false;
        }return false;
        
        
    }
};