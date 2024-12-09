class Solution {
    bool fn(int sidx, int eidx, vector<pair<int,int>> &v)
    {
        int start = 0; int end = v.size()-1;
        int pos = -1; int mid = -1;

        while(start<=end)
        {
            mid = start+(end-start)/2;
            if(v[mid].first >= sidx)
            {
                pos = mid; 
                end = mid-1;
            }
            else
            {
                start = mid+1;
            }
        }
        if(pos == -1)
        {
            if(eidx<= v[v.size()-1].second)
                return true;
            return false;
        }
        if(v[pos].first == sidx)
        {
            if(eidx <= v[pos].second)
                return true;
            return false;
        }
        else
        {
            if(pos-1 <0)
                return false;
            else
            {
                if(sidx >= v[pos-1].first && eidx<= v[pos-1].second)
                    return true;
            }
        }
        return false;
    }
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> answer(queries.size(),false);
        int j = 0; 
        vector<pair<int,int>>v;
        for(int i = 1; i< nums.size(); i++)
        {
            if(nums[i]%2 ==0 && nums[i-1]%2 != 0 || (nums[i-1]%2==0 && nums[i]%2!=0))
            {
                if(i== nums.size()-1)
                {
                    v.push_back({j,i});
                }
                continue;
            }
            else
            {
                v.push_back({j,i-1});
                j=i; continue;
            }
        }
        for(int i = 0; i< queries.size(); i++)
        {
            int start = queries[i][0];
            int end = queries[i][1];
            if(start == end)
            {
                answer[i] = true;
                continue;
                
            }
            answer[i] = fn(start, end, v);
        }return answer;

        
    }
};