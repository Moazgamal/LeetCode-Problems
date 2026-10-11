class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {

       unordered_map<int,int>mp;
       unordered_map<int,int>mp1;
       unordered_map<int,int>mp2;
       int mini = INT_MAX;
       for(int i = 0; i<basket1.size();i++)
       {
            mp[basket1[i]]++;
            mp1[basket1[i]]++;
            mp[basket2[i]]++;
            mp2[basket2[i]]++;
            mini = min(mini, min(basket1[i], basket2[i]));
       }
       for(auto x:mp)
       {
        if(x.second%2!=0)
            return -1;
       }
       vector<pair<int,int>>v1;
       vector<pair<int,int>>v2;

    //    long long acc =0;
    //    unordered_map<int,int>mpx;
       for(auto x: mp)
       {
            int totalFreq = x.second;
            int Freq1 = mp1[x.first];
            int Freq2 = mp2[x.first];
            if(Freq1 < totalFreq/2)
            {
                v1.push_back({x.first, totalFreq/2-Freq1});
                // acc += (totalFreq/2-Freq1);
                // mpx[x.first]=totalFreq/2-Freq1;
            }

            if(Freq2 < totalFreq/2)
            {
                v2.push_back({x.first, totalFreq/2-Freq2});
                // mpx[x.first]=totalFreq/2-Freq2;
            }

            
       }
    //    acc *=2;
    //     cout<<acc<<" "<<mini<<" "<<mpx[mini]<<"\n";
        
    //    long long ans1 =  (acc)*mini - mpx[mini];
       sort(v1.rbegin(), v1.rend());
       sort(v2.begin(), v2.end());
    //    for(int i = 0; i< v1.size(); i++)
    //    {
    //         cout<<v1[i].first<<" "<<v1[i].second<<" v1\n";
    //    }
    //    for(int i = 0; i< v2.size(); i++)
    //    {
    //         cout<<v2[i].first<<" "<<v2[i].second<<" v2\n";
    //    }
    //    long long ans = 0; 
       int i = 0; int j = 0; 
       long long ans3 = 0;
       while(i < v1.size())
       {
            long long val1 = v1[i].first; long long val2 = v2[j].first;
            long long freq1 = v1[i].second; long long freq2 = v2[j].second;
            // cout<<val1<<" "<<val2<<" v\n";
            // cout<<freq1<<" "<<freq2<<" f\n";

            if(freq1 == freq2)
            {
                // ans += (min(val1,val2) * freq1);
                long long u = (min(val1,val2) * freq1);
                long long u2 = (mini*(2*freq1));
                ans3 += min(u,u2);
                i++; j++; continue;
            }
            else if(freq1 > freq2)
            {
                // ans += (min(val1, val2) * freq2);
                v1[i].second = v1[i].second - freq2;

                long long u = (min(val1,val2) * freq2);
                long long u2 = (mini*(2*freq2));
                ans3 += min(u,u2);
                j++;
                continue;
            }
            else
            {
                // ans += (min(val1, val2) * freq1);
                v2[j].second = v2[j].second - freq1;

                long long u = (min(val1,val2) * freq1);
                long long u2 = (mini*(2*freq1));
                ans3 += min(u,u2);

                i++;
                continue;
            }
       }
       return ans3; 
    }
};