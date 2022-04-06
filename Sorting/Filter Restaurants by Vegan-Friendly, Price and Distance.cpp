class Solution {
public:
    
    static bool mycmp(vector<int>first,vector<int>second)
    {
        if(first[1]==second[1])
            return first[0]>second[0];
            
            return first[1]>second[1];
    }
    
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        vector<vector<int>>filtered;
        
        for(int i=0;i<restaurants.size();i++)
        {
            
                if(veganFriendly==0)
                {
                    if(restaurants[i][3]<= maxPrice && restaurants[i][4] <= maxDistance)
                    {
                        filtered.push_back(restaurants[i]);
                    }
                }
                
                else{
                    if(restaurants[i][2]==1 && restaurants[i][3]<= maxPrice && restaurants[i][4] <= maxDistance)
                    {
                     filtered.push_back(restaurants[i]);   
                    }
                }
            
         }
        
        sort(filtered.begin(),filtered.end(),mycmp);
        
        vector<int>res;
        
        for(int i=0;i<filtered.size();i++)
        {
            res.push_back(filtered[i][0]);
        }
        
        return res;
    }
};
