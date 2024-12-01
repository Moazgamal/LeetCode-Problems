class Solution {
public:
    bool checkIfExist(vector<int>& arr) {

        unordered_map<double,int>mp;
        for(int i = 0; i< arr.size(); i++)
        {
            if(mp.count(arr[i]*2)>0 || mp.count(arr[i]/(double)2)>0)
            {
                cout<<arr[i]<<"\n";
                return true;
            }
            mp[arr[i]]++;
        }return false;


        
    }
};