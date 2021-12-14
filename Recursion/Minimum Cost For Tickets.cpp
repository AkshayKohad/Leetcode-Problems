// RECURSION method


class Solution {
public:
    
    int solution(vector<int>&days, vector<int>&costs,int validity,int n)
    {
        if(validity<=0)
        {
            return 0;
        }
        
        if(n==0)
            return 0;
        
        if(days[n-1]>validity)
        {
            return solution(days,costs,validity,n-1);
        }
        
        else if(days[n-1]<validity)
        {
            return solution(days,costs,days[n-1],n);
        }
        
        else{
            int ans = costs[0] + solution(days,costs,validity-1,n);
            int ans1 = costs[1] + solution(days,costs,validity-7,n);
            int ans2 = costs[2] + solution(days,costs,validity-30,n);
            
            int ans3 = min(ans1,ans);
            int ans4 = min(ans2,ans3);
            return ans4;
        }
        
        
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        return solution(days,costs,days[n-1],n);
    }
};
