class TimeMap {
public:
    map<string,map<int,string>>key_timestamp_record; // key -> {timestamp -> value}
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        key_timestamp_record[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(key_timestamp_record.find(key)==key_timestamp_record.end() || key_timestamp_record[key].size()==0)return "";
        auto it = key_timestamp_record[key].lower_bound(timestamp);

        if(it == key_timestamp_record[key].end()){
            return key_timestamp_record[key].rbegin()->second;
        }else{
            if(it->first == timestamp){
                return it->second;
            }else{
                if(it == key_timestamp_record[key].begin())return "";
                --it;
                return it->second;
            }
        }

    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
