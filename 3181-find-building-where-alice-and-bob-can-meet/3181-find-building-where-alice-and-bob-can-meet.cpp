class Solution {
    int BS(int start, int end, vector<pair<int,int>> &v, int target)
    {
        int pos = -1; int mid = -1;
        while(end<=start)
        {
            mid = end + (start-end)/2;
            if(v[mid].first > target)
            {
                pos = mid;
                end = mid+1;
            }
            else
            {
                start = mid-1;
            }
        }
        return pos ;
    }
    
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {

       unordered_map<int, set<pair<int,int>> > mp;
       vector<int> result(queries.size());
       for(int i = 0; i< queries.size(); i++)
       {
            int idx = max(queries[i][0], queries[i][1]);
            int minidx = min(queries[i][0], queries[i][1]);
            int maxi = max(heights[queries[i][0]] , heights[queries[i][1]]);
            if(queries[i][0] == queries[i][1])
            {
                result[i] = queries[i][0];
                continue;
            }
            else if(heights[idx] > heights[minidx])
            {
                result[i] = idx;
                continue;
            }
            mp[idx].insert({maxi,i});
       }
       vector<pair<int,int>> st;
       
       for(int i = heights.size()-1; i >= 0 ; i--)
       {
            if(mp.count(i) > 0)
            {
                int end = 0; 
                for(auto x: mp[i])
                {
                    
                    int idx = BS(st.size()-1, end, st, x.first);
                    if(idx == -1)
                        result[x.second] =-1;
                    else
                        result[x.second] = st[idx].second;
                    
                }
                while(st.size() >0 && st.back().first < heights[i])
                {
                    st.pop_back();
                }
                st.push_back({heights[i],i});
                
            }
            else
            {
                while(st.size() >0 && st.back().first < heights[i])
                {
                    st.pop_back();
                }
                st.push_back({heights[i],i});
            }
       }
       return result;
        
    }
};