class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        
        unordered_map<int,int>mp;
        unordered_map<int,vector<int>>mp2;

        int targetindex =times[targetFriend][0];
        for(int i = 0; i< times.size(); i++)
        {
           mp[times[i][0]]= times[i][1];
           
        }
        int curavball = 0;
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i = 1; i<= targetindex; i++)
        {
            if(mp2.count(i)>0)
            {
                for(auto x: mp2[i])
                {
                    pq.push(x);
                }
            }
            if(mp.count(i)>0)
            {
                if(!pq.empty())
                {
                    if(i == targetindex)
                        return pq.top();
                    int end = mp[i];
                    mp2[end].push_back(pq.top());
                    pq.pop();
                    
                }
                else
                {
                     int end = mp[i];
                    mp2[end].push_back(curavball);
                    curavball++;
                    if(i== targetindex)
                        return curavball-1;
                }
            }
            
        }
        cout<<"**********"<<"\n";
        return 0;
        

    }
};