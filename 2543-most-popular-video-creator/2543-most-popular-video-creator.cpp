class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {

        vector<vector<string>> ans;
        unordered_map<string, long long>mp1;
        unordered_map<long long, unordered_set<string>> mp2;
        unordered_map<string, int>mp3;
        unordered_map<string, string>mp4;
        long long maxi = 0; 
        for(int i = 0; i< creators.size(); i++)
        {
            mp1[creators[i]] += views[i];
            if(mp1[creators[i]] >= maxi)
            {
                maxi = mp1[creators[i]];
                if(mp2[maxi].find(creators[i]) == mp2[maxi].end())
                    mp2[maxi].insert(creators[i]);
            }
            if(views[i] > mp3[creators[i]])
            {
                mp3[creators[i]]= views[i];
                mp4[creators[i]]= ids[i];
            }
            else if(views[i] == mp3[creators[i]])
            {
                if(mp4.count(creators[i]) != 0)
                    mp4[creators[i]]= min(mp4[creators[i]], ids[i]);
                else
                    mp4[creators[i]]= ids[i];
            }
        }

        for(auto x: mp2[maxi])
        {
            ans.push_back({x, mp4[x]});
        }
        return ans; 
        
    }
};