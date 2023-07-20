class Solution {
public:
    
    void update(int x,int y, map<pair<int,int>,int>&mp1,unordered_map<int,int>&mp)
    {
             if(mp1.find({x,y})==mp1.end())
                {
                    mp1[{x,y}] = 1;
                    
                    mp[mp1[{x,y}]]++;
                }
                
                else{
                    mp[mp1[{x,y}]]--;
                    
                    mp1[{x,y}]++;
                    
                     mp[mp1[{x,y}]]++;
                }   
    }
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        
        long long total =(long long) (m-1)*(n-1);
        
        //used to store number of blocks as per count of black cell present
        unordered_map<int,int>mp;
        
        //number of black cell present as per block
        map<pair<int,int>,int>mp1;
        
        for(int i=0;i<coordinates.size();i++)
        {
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            
            //for (x,y) be bottom right of block
            if(x-1>=0 && y-1>=0)
            {
                // always passing the bottom right coordinate relative to position of (x,y)
                update(x,y,mp1,mp);
            }
            
            // for (x,y) bottom left of block
            if(x-1>=0 && y+1<n)
            {
                // always passing the bottom right coordinate relative to position of (x,y)
                update(x,y+1,mp1,mp);
            }
            
            // for (x,y) top right of block
            if(x+1<m && y-1>=0)
            {
                // always passing the bottom right coordinate relative to position of (x,y)
                update(x+1,y,mp1,mp);
            }
            
            // for (x,y) top left of block
            if(x+1<m && y+1<n)
            {
                // always passing the bottom right coordinate relative to position of (x,y)
                update(x+1,y+1,mp1,mp);
            }
        }
        
        vector<long long>result(5);
        
        long long sum = 0;
        
        for(int i=1;i<=4;i++)
        {
            sum += mp[i];
            
            result[i] = mp[i];
        }
        
        result[0] = total - sum;
        
        return result;
    }
};
