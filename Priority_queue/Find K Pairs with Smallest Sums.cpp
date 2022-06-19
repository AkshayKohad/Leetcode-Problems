class Solution {
public:
    vector<pair<int,int>>directions = {{1,0},{0,1}};

    
    vector<vector<int>> kSmallestPairs(vector<int>& a, vector<int>& b, int k) {
        
         //sort(a.begin(),a.end());
    //sort(b.begin(),b.end());
    int n = a.size();
    int m = b.size();
        
    priority_queue<pair<int,pair<int,int>>>pq;
    
    pq.push({-(a[0]+b[0]),{0,0}});
    
    set<pair<int,int>>s;
    s.insert({0,0});
    
    
    vector<vector<int>>res;
    
    while(k--)
    {
        if(pq.size()==0)
            break;
        pair<int,pair<int,int>>curr = pq.top();
        pq.pop();
        
        int val = curr.first;
        int a_index = curr.second.first;
        int b_index = curr.second.second;
        
        res.push_back({a[a_index],b[b_index]});
        
        for(auto k:directions)
        {
            int i = a_index + k.first;
            int j = b_index + k.second;
            
            if(i>=n || j>=m || s.find({i,j})!=s.end())
                continue;
            
            int ans = a[i] + b[j];
            
            pq.push({-ans,{i,j}});
            s.insert({i,j});
        }
        
    }
    
    return res;
        
    }
};
