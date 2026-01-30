class MyHashSet {
public:
    int size;
    vector<int>visited;
    MyHashSet() {
        size = 1000001;
        visited.assign(size,0);
    }
    
    void add(int key) {
        visited[key] = 1;
    }
    
    void remove(int key) {
        visited[key] = 0;
    }
    
    bool contains(int key) {
        return visited[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
