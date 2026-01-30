class MyHashMap {
public:
    vector<int>query;
    int size;
    MyHashMap() {
        size = 1000001;
        query.assign(size,-1);
    }
    
    void put(int key, int value) {
        query[key] = value;
    }
    
    int get(int key) {
        return query[key];
    }
    
    void remove(int key) {
        query[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
