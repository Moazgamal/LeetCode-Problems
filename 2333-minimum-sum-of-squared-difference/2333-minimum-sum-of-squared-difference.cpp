class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        long long ans = 0; 
        int _k = k1+k2;
        int sz = (int)nums1.size();
        unordered_map<int,int>mp;
        int j = 0;
        while(j< sz)
        {
            int Diff = abs(nums1[j]-nums2[j]);
            if(Diff >0)
                mp[abs(Diff)]++;
            j++;
        }
        vector<pair<int,int>>v;
        for(auto &x: mp)
            v.push_back({x.first, x.second});
        
        sort(v.rbegin(), v.rend());
        sz = v.size();
        int i = 0; 
        while(i< sz && _k >0)
        {
            int Diff = v[i].first;
            int Freq = v[i].second;
            int nextDiff = -1; int nextFreq= 0;
            if(i+1 < sz)
            {
                nextDiff = v[i+1].first;
                nextFreq = v[i+1].second;
            }
            int cap = _k/Freq;
            if(nextDiff != -1 && cap>=(Diff-nextDiff))
            {
                v[i+1].second += Freq;
                _k -= (Freq*(Diff-nextDiff));
                i++;
            }
            else if(cap>0)
            {
                int newD = Diff-cap;
                v[i].first = max(0,newD);
                _k -= (cap*Freq);
            }
            else if(cap == 0)
            {
                if(Diff-1>0)
                    v.push_back({Diff-1, _k});
                v[i].second = max(0,Freq-_k);
                _k=0;
            }
        }
        sz = (int)v.size();
        while(i< sz)
        {
            ans += ((long long)v[i].first*v[i].first*v[i].second);
            i++;
        }
        return ans; 
    }
};