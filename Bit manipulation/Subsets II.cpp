class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>s;
        
       int power = pow(2,n)-1;
        vector<vector<int>>res;
        res.push_back({});
        for(int i=1;i<=power;i++)
        {
            vector<int>a;
            for(int j=0;j<n;j++)
            {
                if( (i>>j) & 1 == 1)
                    a.push_back(nums[j]);
            }
            
            if(s.find(a)==s.end())
            {
                s.insert(a);
                res.push_back(a);
            }
        }
       // cout<<s.size();
        
        return res;
    }
};
