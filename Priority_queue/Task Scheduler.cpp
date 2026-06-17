class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int m = tasks.size();
        unordered_map<char,int>mp;
        
        for(auto task : tasks){
            mp[task]++;
        }
        
        priority_queue<pair<int,int>>pq;
        for(auto m : mp){
            pq.push({m.second,m.first});
        }
        
        unordered_map<int,int>last_placed;
        vector<pair<int,int>>temp;
        int cur_placed = 0;
        while(pq.size()>0){
            int cur_window = n+1;
            while(cur_window--){
                if(pq.size()==0){
                    if(temp.size()==0)break;
                    cur_placed++;
                    continue;
                }
                pair<int,int>cur = pq.top();
                pq.pop();
                cur_placed++;
                cur.first--;
                
                if(cur.first>0)temp.push_back(cur);
            }
            
            for(auto t : temp){
                pq.push(t);
            }
            temp.clear();
        }
        return cur_placed;
    }
};
