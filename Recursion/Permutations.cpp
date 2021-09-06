class Solution {
public:
    void solution(vector<int>&nums,int n,vector<int>&b,vector<vector<int>>&a,vector<bool>&visited)
    {
        if(b.size()==n)
        {
            a.push_back(b);
            return;
        }
        
        for(int i=0;i<n;i++)
        {
            if(visited[i]==false)
            {
                visited[i]=true;
                b.push_back(nums[i]);
                solution(nums,n,b,a,visited);
                b.pop_back();
                visited[i]=false;
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>a;
        vector<int>b;
        int n = nums.size();
        vector<bool>visited(n,false);
        
        solution(nums,n,b,a,visited);
        
        return a;
    }
};
