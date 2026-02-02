class UndergroundSystem {
public:
unordered_map<string, unordered_map<string, pair<double,int>>>mp;
unordered_map<int, pair<string,int>>mp3;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp3[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string sta = mp3[id].first;
        int ti = mp3[id].second;
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