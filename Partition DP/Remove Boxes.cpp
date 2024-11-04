class Solution {
public:
    int solve(int left,int right,int streak,vector<int>&boxes,vector<vector<vector<int>>>&memo){
        if(left>right)return 0;

        if(memo[left][right][streak]!=-1)return memo[left][right][streak];

        int default_val = (streak+1)*(streak+1) + solve(left+1,right,0,boxes,memo);

        for(int i=left+1;i<=right;i++){
            
            if(boxes[left]==boxes[i]){
                default_val = max(default_val,solve(left+1,i-1,0,boxes,memo) + solve(i,right,streak+1,boxes,memo));
            }

        }
        return memo[left][right][streak] =  default_val;
    }

    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        vector<vector<vector<int>>>memo(n,vector<vector<int>>(n,vector<int>(n+1,-1)));
        return solve(0,n-1,0,boxes,memo);
    }
};
