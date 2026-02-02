class UndergroundSystem {
public:
unordered_map<string, unordered_map<string, pair<double,int>>>mp;
unordered_map<int, unordered_map<string,int>>mp2;
unordered_map<int, string>mp3;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp2[id][stationName] = t;
        mp3[id] = stationName;
    }
    
    void checkOut(int id, string stationName, int t) {
        string sta = mp3[id];
        int ti = mp2[id][sta];
        mp[sta][stationName].first += (t-ti);
        mp[sta][stationName].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        return mp[startStation][endStation].first/mp[startStation][endStation].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */