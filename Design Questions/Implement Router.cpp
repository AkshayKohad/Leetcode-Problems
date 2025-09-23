class Router {
public:

    int memoryCapacity;
    int curCapacity;
    // {source,{destination,timestamp}}
    deque<pair<int,pair<int,int>>>packets;
    // destination - timestamp;
    unordered_map<int,vector<int>>packets_timestamp;

    unordered_set<string>packets_record;

    Router(int memoryLimit) {
        curCapacity = 0;
        memoryCapacity = memoryLimit;
    }
    
    bool isFull(){
        if(curCapacity == memoryCapacity)return true;
        return false;
    }

    bool isEmpty(){
        if(curCapacity == 0)return true;
        return false;
    }
    string makeKey(int source,int destination,int timestamp){
        return to_string(source) + "#" + to_string(destination) + "#" + to_string(timestamp);
    }
    bool isDuplicate(int source,int destination,int timestamp){
        if(packets_record.find(makeKey(source,destination,timestamp)) != packets_record.end()) return true;

        return false;
    }


    bool addPacket(int source, int destination, int timestamp) {
        if(isDuplicate(source,destination,timestamp)){
            return false;
        }
       
        if(isFull()){
            pair<int,pair<int,int>>cur = packets.front();
            packets.pop_front();
            int cur_source = cur.first;
            int cur_destination = cur.second.first;
            int cur_timestamp = cur.second.second;

            packets_record.erase(makeKey(cur_source,cur_destination,cur_timestamp));
            
            auto &vec = packets_timestamp[cur_destination];
            if (!vec.empty() && vec.front() == cur_timestamp) {
                vec.erase(vec.begin()); // O(n), but amortized small since oldest always in front
            }
            curCapacity--;
        }
        packets.push_back({source,{destination,timestamp}});
        packets_record.insert(makeKey(source,destination,timestamp));
        packets_timestamp[destination].push_back(timestamp);
        curCapacity++;
        return true;
    }
    
    vector<int> forwardPacket() {

        if(isEmpty())return {};

        pair<int,pair<int,int>>cur = packets.front();
        packets.pop_front();
        int cur_source = cur.first;
        int cur_destination = cur.second.first;
        int cur_timestamp = cur.second.second;
        packets_record.erase(makeKey(cur_source,cur_destination,cur_timestamp));
        auto &vec = packets_timestamp[cur_destination];
            if (!vec.empty() && vec.front() == cur_timestamp) {
                vec.erase(vec.begin()); // O(n), but amortized small since oldest always in front
            }
        curCapacity--;

        int source = cur.first;
        int destination = cur.second.first;
        int timestamp = cur.second.second;

        return {source,destination,timestamp};
    }
    
    int getCount(int destination, int startTime, int endTime) {
        vector<int>&dq = packets_timestamp[destination];
        if(dq.size()==0)return 0;
        
         auto it = lower_bound(dq.begin(), dq.end(), startTime);
         auto it2 = upper_bound(dq.begin(), dq.end(), endTime);

        
        int count = max(0,(int)(it2-it));

        return count; 
    }
};

/**
 * Your Router object will be instantiated and called as such:
 * Router* obj = new Router(memoryLimit);
 * bool param_1 = obj->addPacket(source,destination,timestamp);
 * vector<int> param_2 = obj->forwardPacket();
 * int param_3 = obj->getCount(destination,startTime,endTime);
 */
