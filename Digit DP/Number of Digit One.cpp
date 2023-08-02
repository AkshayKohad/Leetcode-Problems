class Solution {
public:

#define ll long long

ll dp[11][11][2];

void reset()
{
    for(int i=0;i<11;i++)
    {
       for(int j=0;j<11;j++)
       {
            for(int k=0;k<2;k++)
            {
                dp[i][j][k] = -1;
            }
       }    
    }
}

ll solve(string &s,ll cur_index,ll count,bool tight)
{
    if(cur_index==s.length())
    {
   // cout<<count<<endl;    
    return count;
    }
    if(dp[cur_index][count][tight ? 1:0]!=-1)
    return dp[cur_index][count][tight ? 1:0];

  ll limit = s[cur_index] - '0';

    if(!tight)
    limit = 9;
    
    ll res = 0;

    for(ll cur_digit = 0;cur_digit<=limit;cur_digit++)
    {
        bool next_tight = tight && (cur_digit == limit);

        if(cur_digit == 1)
        {
            res = res + solve(s,cur_index+1,count+1,next_tight);
        } 
        else{
            res = res + solve(s,cur_index+1,count,next_tight);
        }
    }

    return dp[cur_index][count][tight ? 1:0] = res;
}
    int countDigitOne(int n) {
        reset();
        string s;

        while(n>0)
        {
            int rem = n%10;
            s.push_back(rem + '0');

            n = n/10;
        } 
       reverse(s.begin(),s.end()); 
       //cout<<s<<endl;
        return solve(s,0,0,true);
    }
};
