class Solution {
public:
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        vector<long long> answer(nums1.size(),0);
        unordered_map<int,int>mp2;
        for(int i = 0; i< nums1.size(); i++)
            {
                v.push_back({nums1[i],i});
                mp2[i] = nums2[i];
            }
        sort(v.begin(), v.end());
        vector<int>v2(nums1.size(),0);
        unordered_map<int,int>mp;
        for(int i = 0; i< v.size(); i++)
            {
                v2[i] = mp2[v[i].second];
                int value = v[i].first;
                if(mp.count(value)==0)
                {
                    mp[value] = i;
                }
            }
        
        vector<long long> bestSum(nums1.size(),0);
        long long best = 0; 
        priority_queue<int, vector<int>, greater<int>> pq;
        int _k = 1; 
        pq.push(v2[0]);
        best = v2[0];
        for(int i = 1; i< v2.size(); i++)
            {
                bestSum[i] = best;
                best += v2[i];
                pq.push(v2[i]);
                _k++;
                if(_k<=k)
                    continue;
                else
                {
                    long long x = pq.top(); pq.pop();
                    best -= x;
                    _k--;
                }
            }
        for(int i = 0; i< nums1.size(); i++)
            {
                int idx = mp[nums1[i]];
                if(idx ==0)
                    continue;
                answer[i] = bestSum[idx];
            }
        return answer;
        
        
        
        
        
    }
};