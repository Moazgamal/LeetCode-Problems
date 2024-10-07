class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int conv = 0;
        for(int op = ceil(log2(k)); op>=1; op--)
        {
            cout<<op<<" ";
            if(k > ((1ll << op)/2))
            {
                conv+= (operations[op-1]);
                k -= ((1ll<< op)/2);
            }
        }
        conv=conv%26;
        return 'a'+conv;
        
    }
};