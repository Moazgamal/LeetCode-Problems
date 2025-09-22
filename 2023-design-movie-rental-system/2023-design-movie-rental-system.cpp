class MovieRentingSystem {
public:
map<int, set<pair<int,int>>>mp1;
map<int, set<pair<int,int>>>mp2;
map<int, set<pair<int,int>>>mp4;
unordered_map<int, set<pair<int,int>>> mp3; 
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for(int i = 0; i< entries.size(); i++)
        {
            int shop = entries[i][0]; 
            int movie = entries[i][1];
            int price = entries[i][2];
            mp1[price].insert({shop, movie});
            mp3[shop].insert({movie, price});
            mp4[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        int cnt = 0; 
        vector<int> ans;
        for(auto x: mp4[movie])
        {
            int price = x.first, shop = x.second;
            if(mp1[price].find({shop, movie}) != mp1[price].end())
            {
                ans.push_back(x.second);
                cnt++;
            }
            if(cnt == 5)
                break;
        }return ans; 

    }
    
    void rent(int shop, int movie) {
        int p = 0; 
        for(auto x: mp3[shop])
        {
            if(x.first == movie)
            {
                p = x.second; break;
            }
        }
        mp1[p].erase({shop, movie});
        mp2[p].insert({shop, movie});
    }
    
    void drop(int shop, int movie) {
        int p = 0; 
        for(auto x: mp3[shop])
        {
            if(x.first == movie)
            {
                p = x.second; break;
            }
        }
        mp2[p].erase({shop, movie});
        mp1[p].insert({shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>>res;
        int cnt = 0; 
        for(auto x: mp2)
        {
            for(auto y: x.second)
            {
                res.push_back({y.first, y.second});
                cnt++;
                if(cnt == 5)
                    break;
            }
            if(cnt == 5)
                break;
        }
        return res; 
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */