class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        
        unordered_map<int,int>mp;
       priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = (int)arr.size()-1; i >= 0; i--)
        {
            if(pq.empty())
            {
                pq.push(arr[i]);
                mp[arr[i]]= i;
            }
            else
            {
                if(pq.top() < arr[i])
                {
                    int last = 0;
                    while(!pq.empty() && pq.top() < arr[i])
                    {
                        last = mp[pq.top()];
                        pq.pop();
                    }
                    swap(arr[last], arr[i]);
                    return arr;
                }
                else
                {
                    pq.push(arr[i]);
                    mp[arr[i]]= i;
                }
            }
        }
        return arr;
    }
};