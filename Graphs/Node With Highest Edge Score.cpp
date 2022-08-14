class Solution {
public:
    int edgeScore(vector<int>& edges) {
        
        int n = edges.size();
        
        vector<long long int>res(n,0);
        
        long long int max_res = 0;
        for(int i=0;i<n;i++)
        {
            res[edges[i]] += i;
            
            max_res = max(max_res,res[edges[i]]);
        }
        
        
        for(int i=0;i<n;i++)
        {
            if(res[i]==max_res)
                return i;
        }
       return 0; 
        
    }
};
