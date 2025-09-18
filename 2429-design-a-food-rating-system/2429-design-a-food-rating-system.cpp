class FoodRatings {
public:
    struct CustomCmp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) const {
        if (a.first != b.first) 
            return a.first > b.first; // larger int comes first
        return a.second < b.second;   // smaller string comes first
    }
};
unordered_map<string, int> rate; unordered_map<string , string> type;
unordered_map<string, set<pair<int,string>, CustomCmp>>mp;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i = 0; i< ratings.size(); i++)
        {
            rate[foods[i]]= ratings[i]; type[foods[i]]= cuisines[i];
            mp[cuisines[i]].insert({ratings[i], foods[i]});
        }
    }
    
    void changeRating(string food, int newRating) {
        string t = type[food];
        int r = rate[food];
        mp[t].erase({r, food});
        rate[food]= newRating;
        mp[t].insert({rate[food], food});
    }
    
    string highestRated(string cuisine) {
        auto key =  *mp[cuisine].begin();
        return key.second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */