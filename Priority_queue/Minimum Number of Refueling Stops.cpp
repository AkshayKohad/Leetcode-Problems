class Solution {
public:
    
    #define ll long long
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
     
        priority_queue<ll>pq;
        
        ll n = stations.size();
        
        ll initial_fuel = startFuel;
        
        ll cur_position = 0;
        ll res = 0;
        
        for(ll i=0;i<n;i++)
        {
            
            ll position = stations[i][0];
            
            ll fuel = stations[i][1];
            
            ll dist  = position - cur_position;
            
            if(initial_fuel >= dist)
            {
                initial_fuel -= dist;
                pq.push(fuel);
                cur_position = position;
            }
            
            else{
                
                while(pq.size()>0 && initial_fuel<dist)
                {
                    initial_fuel += pq.top();
                    pq.pop();
                    res++;
                }
                
                if(initial_fuel<dist)
                {
                    return -1;
                }
                
                initial_fuel -= dist;
                
                pq.push(fuel);
                
                cur_position = position;
                
            }
        }
        
        
        ll dist = target - cur_position;
        
         while(pq.size()>0 && initial_fuel<dist)
         {
                    initial_fuel += pq.top();
                    pq.pop();
                    res++;
         }
                
                if(initial_fuel<dist)
                {
                    return -1;
                }
        
        return res;
    }
};
