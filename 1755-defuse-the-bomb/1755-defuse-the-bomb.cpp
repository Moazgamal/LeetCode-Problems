class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>res(code.size(),0);
        if(k==0)
        {
            for(int i = 0; i<code.size(); i++)
            {
                code[i]=0;
            }
        }
        if(k>0)
        {
            int i = 1; int j = k;
            int sum = 0;
            int t = 1;
            while(t<=j)
            {
                sum+=code[t];t++;
            }
            int idx = 0; 
            res[idx]=sum;
            idx++;
            t = i;
            while(idx<code.size())
            {
                sum-=code[t];
                t++; j++; 
                if(t>=code.size())
                    t=0;
                if(j>=code.size())
                    j=0;
                sum+=code[j];
                res[idx++] = sum;
            }

        }
        if(k<0)
        {
            int i = code.size()-2; int j = code.size()-2-(-k)+1;
            int sum = 0;
            int t = i;
            while(t>=j)
            {
                sum+=code[t];t--;
            }
            int idx = code.size()-1; 
            res[idx]=sum;
            idx--;
            t = i;
            while(idx>=0)
            {
                sum-=code[t];
                t--; j--; 
                if(t<0)
                    t=code.size()-1;
                if(j<0)
                    j=code.size()-1;
                cout<<j;
                sum+=code[j];
                res[idx--] = sum;
            }

        }
        return res;
        
        
        
    }
};