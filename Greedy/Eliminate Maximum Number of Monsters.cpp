class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
     
        double initial_time  = 0;
        
        int monster_kill_count = 0;
        
        
        priority_queue<double,vector<double>,greater<double>>pq;
        
        
        for(int i=0;i<dist.size();i++)
        {
            double cur_time = (double)dist[i]/speed[i];
            
            pq.push(cur_time);
        }
        
        while(pq.size()>0)
        {
            if(initial_time < pq.top())
            {
                pq.pop();
                initial_time++;
                monster_kill_count++;
            }
            
            else{
                break;
            }
        }
        
        
        return monster_kill_count;
    }
};
