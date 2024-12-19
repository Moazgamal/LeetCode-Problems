class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {

        int l = -1; 
        int r = -1;
        int cnt = 0;
        
        for(int i = 0; i< arr.size(); i++)
        {
            if(arr[i] == i)
            {
                if(l!=-1 && r != -1 && i >= l && i <= r)
                {
                    continue;
                }
                else
                    cnt++;
                
            }
            else
            {
                if(l == -1 && r == -1)
                {
                    l = i;
                    r =  arr[i];
                    cnt++;
                }
                else if(i >= l && i <= r)
                {
                    l = i ;
                    r = max(r,  arr[i]);
                }
                else
                {
                    l = i ;
                    r = arr[i];
                    cnt++;
                }
            }
        }return cnt;
        
    }
};