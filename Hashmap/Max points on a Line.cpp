class Solution {
public:
    
    //Using y = mx + c;
    
    // find all possible lines
    
    int maxPoints(vector<vector<int>>& points) {
        
        if(points.size()==1)
            return 1;
        
        
        map<pair<double,double>,set<pair<int,int>>>mp;
        
         int res = 0;
       
        
        
        for(int i=0;i<points.size();i++)
        {
            int count =1;
            for(int j=i+1;j<points.size();j++)
            {
                if(points[i][0] == points[j][0])
                {
                    
                    count++;
                  
                    
                }
                
                else if(points[i][1] == points[j][1])
                {
                    mp[{0,points[i][1]}].insert({points[i][0],points[i][1]});
                    mp[{0,points[i][1]}].insert({points[j][0],points[j][1]});
                }
                
                else{
                    
                    
                    double delta_y = (double)(points[j][1]-points[i][1]);
                    double delta_x = (double)(points[j][0]-points[i][0]);
                        
                    double m =  delta_y/delta_x;
                    
                    double c = ((double) points[j][1] - m*(double) points[j][0]);
                    
                    mp[{m,c}].insert({points[i][0],points[i][1]});
                    mp[{m,c}].insert({points[j][0],points[j][1]});
                    
                }
            }
            
            if(res<count)
                res = count;
        }
        
        
        
        for(auto k:mp)
        {
            int si = k.second.size();
            if(res<si)
                res = si;
        }
        
        return res;
    }
};
