class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        vector<int> lastSmaller(arr.size(), -1);

        for(int i = 0; i< arr.size(); i++)
        {
            for(int j = arr.size()-1; j >i; j--)
            {
                if(arr[j] < arr[i])
                {
                    lastSmaller[i]= j;
                    break;
                }
            }
        }
        
        int ans = 0; 
        for(int i = 0; i < arr.size(); )
        {
            if(lastSmaller[i] == -1)
            {
                ans++; i++; continue;
            }
            int OLDSmaller = i;
            int lastSmall = lastSmaller[i];
            while(OLDSmaller < lastSmall)
            {
                int j = OLDSmaller; 
                OLDSmaller = lastSmall;
                while(j < lastSmall)
                {
                    lastSmall = max(lastSmall, lastSmaller[j]);
                    j++;
                }
                lastSmall = max(lastSmall, lastSmaller[j]);
            }
            ans++;
            i = lastSmall+1;
            cout<<i<<" \n";
        }
        return ans; 
    }
};