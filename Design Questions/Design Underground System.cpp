class UndergroundSystem {
public:
    map<pair<string,string>,pair<int,int>>mp;
    unordered_map<int,pair<string,int>>check_in;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        check_in[id] = {stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        string check_in_station = check_in[id].first;
        int start_time = check_in[id].second;

        int time_sum = mp[{check_in_station,stationName}].first;
        int cnt = mp[{check_in_station,stationName}].second;

        mp[{check_in_station,stationName}] = {time_sum + t - start_time, cnt+1};
        check_in.erase(id);
    }
    
    double getAverageTime(string startStation, string endStation) {
       int time_sum = mp[{startStation,endStation}].first;
       int cnt = mp[{startStation,endStation}].second;

       return (double)time_sum/cnt;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
