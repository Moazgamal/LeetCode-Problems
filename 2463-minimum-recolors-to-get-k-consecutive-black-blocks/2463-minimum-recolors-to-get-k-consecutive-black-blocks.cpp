class Solution {
public:
    int minimumRecolors(string blocks, int k) {
    
        vector<pair<int,int>> indicies;
        int ans = INT_MAX;
        for(int i = 0; i< blocks.size(); i++)
        {
            if(blocks[i]=='B')
            {
                int j = i;
                while(j< blocks.size() && blocks[j] == 'B')
                    j++;
                if(j-i >= k)
                    return 0; 
                indicies.push_back({i,j-1});
                i=j;
            }
        }
        if(indicies.size() == 0)
            return k;
        if(indicies.size() == 1)
        {
            int value = indicies[0].second - indicies[0].first +1;
            if(value >=k)
                return 0; 
            k-=value;
            return k; 
        }
        for(int i = 0; i< indicies.size(); i++)
        {
            int totalOperations = 0; 
            int start  = indicies[i].first;
            int end  = indicies[i].second;
            int sum = end-start+1;
            if(sum >=k)
                return 0; 
            int rest = k; 
            rest -= sum;
            for(int j = i+1; j< indicies.size(); j++)
            {
                int start2  = indicies[j].first;
                int end2  = indicies[j].second;
                int currentOperation = (start2 - end - 1);
                if(rest <=0)
                {
                    ans = min(ans, totalOperations);
                    break;
                }
                if(rest - currentOperation ==0)
                {
                    ans = min(ans, totalOperations+currentOperation);
                    break;
                }
                else if(rest - currentOperation <0)
                {
                    ans = min(ans, totalOperations+rest);
                    break;
                }
                else
                {
                    rest -=currentOperation;
                    rest = rest - (end2-start2+1);
                    totalOperations += currentOperation;
                    if(rest<=0)
                    {
                        ans = min(ans, totalOperations);
                    }
                }
                end = end2; 
                start = start2;
            }
            if(rest >0)
            {
                ans = min(ans, totalOperations+rest);
            }
        }return ans;


    }
};