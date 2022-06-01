class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>b;
        b.push_back({1});
        
        if(numRows==1)
            return b;
        
        b.push_back({1,1});
        
        if(numRows==2)
            return b;
        
        for(int i=3;i<=numRows;i++)
        {
            vector<int>curr;
            
            vector<int>prev = b[b.size()-1];
            
            curr.push_back(1);
            
            for(int j=0;j<prev.size()-1;j++)
            {
                curr.push_back(prev[j]+prev[j+1]);
            }
            
            curr.push_back(1);
            
            b.push_back(curr);
        }
        
        return b;
    }
};
