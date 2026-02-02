class RideSharingSystem {
public:
    set<pair<int,int>>rider_order; // id-rider_id
    set<pair<int,int>>driver_order; // id-driver_id
    unordered_map<int,int>rider_id; // rider-id
    int rider_cap;
    int driver_cap;
    
    RideSharingSystem() {
        rider_cap = 0;
        driver_cap = 0;
    }
    
    void addRider(int riderId) {
        rider_cap++;
        rider_order.insert({rider_cap,riderId});
        rider_id[riderId] = rider_cap;
    }
    
    void addDriver(int driverId) {
        driver_cap++;
        driver_order.insert({driver_cap,driverId});
    }
    
    vector<int> matchDriverWithRider() {
        if(rider_order.size()==0 || driver_order.size()==0)return {-1,-1};

        auto rider_it = rider_order.begin();
        auto driver_it = driver_order.begin();

        

        rider_id.erase(rider_it->second);
        vector<int>res = {driver_it->second,rider_it->second}; 
        rider_order.erase(rider_it);
        driver_order.erase(driver_it);
        return res;
    }
    
    void cancelRider(int riderId) {
        int id_num = rider_id[riderId];
        rider_order.erase({id_num,riderId});
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
