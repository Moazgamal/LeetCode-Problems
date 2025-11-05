class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        
        vector<pair<int,int>>mp(arr.size()+1);
        vector<long long>rows(arr.size()+1);
        vector<long long>cols(arr.size()+1);
        for(int i = 0; i< mat.size(); i++)
        {
            for(int j = 0; j< mat[0].size(); j++)
            {
                mp[mat[i][j]]= {i,j};
                rows[i]+= mat[i][j];
                cols[j]+=mat[i][j];
            }
        }

        for(int i = 0; i< arr.size(); i++)
        {
            int row = mp[arr[i]].first;
            int col = mp[arr[i]].second;
            rows[row]-=arr[i];
            if(rows[row] == 0)
                return i; 
            cols[col]-=arr[i];
            if(cols[col] == 0)
                return i; 
        }
        return 0; 
    }
};