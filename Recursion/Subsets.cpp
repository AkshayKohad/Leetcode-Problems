class Solution {
public:
    
    void solve(vector<int>a,vector<vector<int>>&b,vector<int>c,int i)
    {
        if(i==a.size())
        {
            b.push_back(c);
            return;
        }
        
        solve(a,b,c,i+1);
        c.push_back(a[i]);
        solve(a,b,c,i+1);
        
        return;
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        unordered_set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        
        vector<int>a;
        for(auto x: s)
        {
            a.push_back(x);
        }
        
        vector<vector<int>>b;
        
        vector<int>c;
        
        solve(a,b,c,0);
        return b;
        
    }
};
