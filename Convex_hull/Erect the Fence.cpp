class Solution {
public:
    
    
    static  bool mycmp(vector<int>first,vector<int>second)
    {
        if(first[0] == second[0])
        {
            return first[1] < second[1];
        }
        
        return first[0] < second[0];
    }
    
    
    bool cw(vector<int>a,vector<int>b,vector<int>c)
    {
        return a[0]*(c[1]-b[1]) + b[0]*(a[1]-c[1]) + c[0]*(b[1]-a[1]) > 0;
    }
    
    bool ccw(vector<int>a,vector<int>b,vector<int>c)
    {
        return a[0]*(c[1]-b[1]) + b[0]*(a[1]-c[1]) + c[0]*(b[1]-a[1]) < 0;
    }
    
    
    vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        
        
         int n = trees.size();
        
        if(n<=2)
            return trees;
        
        sort(trees.begin(),trees.end(),mycmp);
        
        vector<int>first = {trees[0][0],trees[0][1]};
        
        vector<int>last = {trees[n-1][0],trees[n-1][1]};
        
        
        vector<vector<int>>up;
        vector<vector<int>>down;
        

        
        up.push_back(first);
        down.push_back(first);
        
        for(int i=1;i<n;i++)
        {
            if(i==n-1 || !ccw(first,trees[i],last))
            {
                while(up.size()>=2 && ccw(up[up.size()-2],up[up.size()-1],trees[i]))
                {
                    up.pop_back();
                }
                
                up.push_back(trees[i]);
            }
            
            
            if(i==n-1 || !cw(first,trees[i],last))
            {
              while(down.size()>=2 && cw(down[down.size()-2],down[down.size()-1],trees[i]))
                {
                    down.pop_back();
                }
                
                down.push_back(trees[i]);   
            }
        }
        
        
       vector<vector<int>>res;
        
        set<pair<int,int>>s;
        
        for(int i=0;i<up.size();i++)
        {
            int x = up[i][0];
            int y = up[i][1];
            
            
            if(s.find({x,y})==s.end())
            {
                res.push_back(up[i]);
                s.insert({x,y});
            }
            
        }
        
        
        for(int i=0;i<down.size();i++)
        {
            int x = down[i][0];
            int y = down[i][1];
            
            
            if(s.find({x,y})==s.end())
            {
                res.push_back(down[i]);
                s.insert({x,y});
            }
        }
        
        return res;
        
    }
};
