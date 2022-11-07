class Solution {
public:
    
    
    int solve(int i,vector<int>&nums1,vector<int>&nums2,int count,int &n,vector<vector<int>>&memo)
    {
        if(i==n)
            return 0;
        
        //if(memo.find(i)!=memo.end() && memo[i].find(count)!=memo[i].end())
        if(memo[i][count]!=-1)  
        return memo[i][count];
        
        int res = INT_MAX;
        for(int j=0;j<n;j++)
        {
            
            int bit = (count & (1<<j));
            
           // cout<<bit<<"->"<<endl;
            if(bit!=0)
            {
              //  cout<<bit<<endl;
                continue;
            }
             int new_count = (count | (1 << j));
           // count = count + pow(2,j);
            
            int val = nums1[i] ^ nums2[j];
            
            int ans = val+solve(i+1,nums1,nums2,new_count,n,memo);
            
            res = min(ans,res);
                        
            //count = count - pow(2,j);    
            
        }
            
        return memo[i][count] = res;
    }
    
    
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size();
        
       // unordered_map<int,unordered_map<int,int>>memo;
        
        vector<vector<int>>memo(n+1,vector<int>(1<<n+1,-1));
        
        int result =  solve(0,nums1,nums2,0,n,memo);
        
        return result;
    }
};
