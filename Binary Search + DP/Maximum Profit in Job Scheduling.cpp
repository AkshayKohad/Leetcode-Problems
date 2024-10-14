class Solution {
public:

    int solve(int i,int &n,vector<vector<int>>&job_details,vector<int>&memo){
        if(i==n)return 0;

        if(memo[i]!=-1)return memo[i];

        int res = 0;
        int res1 = 0;

      
        res = solve(i+1,n,job_details,memo);
        
        
            int l=i+1;
            int r=n-1;
            int ti = job_details[i][1];
            int ans=-1;
            while(l<=r){
                int mid = (l+r)/2;
                int next_ti = job_details[mid][0];

                if(ti>next_ti){
                  l=mid+1;
                }else{
                    ans = mid;
                    r=mid-1;
                }

            }

            if(ans==-1)res1=job_details[i][2];
            else res1 = job_details[i][2]+solve(ans,n,job_details,memo);

            return memo[i] = max(res,res1);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        
        int n = startTime.size();
        vector<vector<int>>job_details;
        for (int i=0;i<n;i++){
                job_details.push_back({startTime[i],endTime[i],profit[i]});
        }

        sort(job_details.begin(),job_details.end());
        
        vector<int>memo(n+1,-1);
        return solve(0,n,job_details,memo);

    }
};
