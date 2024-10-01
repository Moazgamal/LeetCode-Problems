class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        unordered_map<int,int> mp;
        for(int i = 0; i< arr.size(); i++)
        {
            int rem = ((arr[i]%k)+k)%k;
            mp[rem]++;
        }
        for(auto x: mp)
        {
            if(x.first ==0 && x.second %2 !=0)
                return false;
            if(x.first !=0 && mp[k-x.first] != x.second)
                return false;
        }return true;
        
    }
};