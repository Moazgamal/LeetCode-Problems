class Solution {
    int NumberOfBits(int num)
    {
        int cnt = 0; 
        while(num > 0)
        {
            if(num %2 == 1)
                cnt++;
            num /= 2;
        }return cnt;
    }
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>ans;
        vector<pair<int,int>>v;
        int i = 0;  int sz = (int)arr.size();
        while(i< sz)
        {
            int numberOfBits = NumberOfBits(arr[i]);
            v.push_back({numberOfBits, arr[i]});
            i++;
        }
        sort(v.begin(), v.end());
        i = 0; 
        while(i < sz)
        {
            ans.push_back(v[i].second); i++;
        }return ans; 
    }
};