class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        if(arr.size()==0)
            return {}:
        vector<int> result(arr.size());
        vector<pair<int,int>>v;
        for(int i =0; i< arr.size(); i++)
        {
            v.push_back({arr[i],i});
        }sort(v.begin(), v.end());
        result[v[0].second]=1;
        for(int i =1; i< v.size(); i++)
        {
            if(v[i].first == v[i-1].first)
            {
                result[v[i].second]= result[v[i-1].second];
            }
            else
                result[v[i].second]= result[v[i-1].second]+1;
            
        }return result;
        
    }
};