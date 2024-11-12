class Solution {
    
int bs(int target, int start, int end, vector<vector<int>>&items)
{
    int mid = -1; int pos = -1;
    while(start<=end)
    {
        mid = start + (end-start)/2;
        if(items[mid][0] > target)
        {
            pos = mid;
            end=mid -1;
        }
        else
        {
            start = mid+1;
        }
    }
    if(pos ==0)
        return 0;
    return items[pos-1][1];
}
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {

        sort(items.begin(), items.end());
        int maxi = items[0][1];
        for(int i = 1; i< items.size(); i++)
        {
            maxi = max(items[i][1], maxi);
            items[i][1]= maxi;
        }
        for(int i = 0;i< queries.size(); i++)
        {
            if(queries[i] < items[0][0])
            {
                queries[i]=0; continue;
            }
            if(queries[i] >= items[items.size()-1][0])
            {
                queries[i] = items[items.size()-1][1]; continue;
            }

            int x = bs(queries[i], 0, items.size()-1, items);
            queries[i]= x;
        }return queries;
       


        
    }
};