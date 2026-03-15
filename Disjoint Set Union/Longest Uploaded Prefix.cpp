class LUPrefix {
public:
    vector<int>parent;
    vector<int>video_status;
    int cap;
    LUPrefix(int n) {
        cap = n;
        parent.assign(n+1,-1);
        video_status.assign(n+1,-1);
        video_status[0] = 1;
    }
    
    int find_parent(int val){
        if(parent[val]==-1)return val;

        return parent[val] = find_parent(parent[val]);
    }
    void upload(int video) {
        video_status[video] = video;

        if(video_status[video-1]!=-1){
            parent[video] = find_parent(video-1);
        }
        if(video+1 <= cap && video_status[video+1]!=-1){
            parent[video+1] = find_parent(video);
        }
    }
    
    int longest() {
        int l = 1;
        int r = cap;
        int ans = 0;

        while(l<=r){
            int mid = (r-l)/2 + l;
            int par = find_parent(mid);
            if(par == 0){
                ans = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }

        return ans;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */
