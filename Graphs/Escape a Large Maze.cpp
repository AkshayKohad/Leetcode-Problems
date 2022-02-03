class Solution {
public:
set<pair<int,int>>block;
    int max_area;
    bool isValid(int x,int y)
    {
        if(x<0 || y<0|| x>=1000000 || y>=1000000)
            return false;
        if(block.find({x,y})==block.end())
            return true;
        return false;
    }
    bool isPossible(vector<int>& source,vector<int>&target)
    {
         set<pair<int,int>> visited;
        visited.insert({source[0],source[1]});
        
        queue<pair<int,int>>q;
        q.push(make_pair(source[0],source[1]));
        int t=1;
        
        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
          
            if(x==target[0] && y== target[1])
                return true;
            if(t>max_area)
                return true;
            if(isValid(x-1,y) && visited.find({x-1,y})==visited.end())
            {
                t++;
                visited.insert({x-1,y});
                q.push(make_pair(x-1,y));
            }
            if(isValid(x+1,y) && visited.find({x+1,y})==visited.end())
            {
                t++;
               visited.insert({x+1,y});
                q.push(make_pair(x+1,y));   
            }
            if(isValid(x,y-1) && visited.find({x,y-1})==visited.end())
            {
                t++;
               visited.insert({x,y-1});
                q.push(make_pair(x,y-1));
            }
            if(isValid(x,y+1) && visited.find({x,y+1})==visited.end())
            {
                t++;
                visited.insert({x,y+1});
                q.push(make_pair(x,y+1));
            }
        }
        return false;
    }
    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target)     {
        int cnt=0;
        
        for(int i=0;i<blocked.size();i++)
        {
            cnt++;
            block.insert({blocked[i][0],blocked[i][1]});
        }
        max_area = (cnt*(cnt-1))/2;
        return isPossible(source,target) && isPossible(target,source);
    }
};
