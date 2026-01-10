class Solution {
    int arr[1001][1001];
    int fn(int idx1, int idx2, string &s1, string &s2)
    {
        if(idx1 == s1.size() && idx2 == s2.size())
            return 0 ;
        auto &ret = arr[idx1][idx2];
        if(ret != -1)
            return ret; 
        if(idx1 == s1.size())
        {
            int acc = 0; 
            for(int i =idx2; i< s2.size(); i++)
            {
                acc += ((int)s2[i]);
            }
            return ret = acc;
        }
        if(idx2 == s2.size())
        {
            int acc = 0; 
            for(int i =idx1; i< s1.size(); i++)
            {
                acc += ((int)s1[i]);
            }
            return ret = acc;
        }

        ret = (int)s1[idx1]+fn(idx1+1, idx2, s1, s2);
        ret = min(ret, (int)s2[idx2]+fn(idx1, idx2+1, s1, s2));
        if(s1[idx1] == s2[idx2])
        {
            ret = min(ret, fn(idx1+1, idx2+1, s1, s2));
        }
        return ret;
    }
public:
    int minimumDeleteSum(string s1, string s2) {
        
        memset(arr,INT_MAX,sizeof(arr));
        
        return fn(0,0,s1,s2);
    }
};