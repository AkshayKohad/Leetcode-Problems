class Solution {
public:

#define ll long long

#define mod 1000000007

ll dp[24][401][2];

void reset()
{
    for(int i=0;i<24;i++)
    {
        for(int j=0;j<401;j++)
        {
            for(int k=0;k<2;k++)
            {
                dp[i][j][k] = -1;
            }
        }
    }


}

   ll solve(string num,int cur_index,int &min_sum,int &max_sum,int sum,bool tight)
   {
       if(cur_index == num.length())
       {
           if(sum>=min_sum && sum<=max_sum)
           return 1;

           return 0;
       }

       if(dp[cur_index][sum][tight]!=-1)
       return dp[cur_index][sum][tight];

       int limit = num[cur_index] - '0';

       if(!tight)
       limit = 9;

      ll res = 0;

       for(int cur_digit = 0;cur_digit<=limit;cur_digit++)
       {
           bool next_tight = tight && (cur_digit == limit);
           
           res = ( res + solve(num,cur_index+1,min_sum,max_sum,sum+cur_digit,next_tight)) % mod;

       }

       return dp[cur_index][sum][tight] = res;
   }
    int count(string num1, string num2, int min_sum, int max_sum) {
        
        reset();

        ll result = solve(num2,0,min_sum,max_sum,0,true);

        reset();

        result -= solve(num1,0,min_sum,max_sum,0,true);

        result = (result+mod)%mod;

        bool is_valid_num1 = true;
 
        int sum = 0;

        for(int i=0;i<num1.length();i++)
        {
            int val = num1[i]-'0';
            
            sum += val;
        }

        if(sum<min_sum || sum>max_sum)
        is_valid_num1 = false;

        result = (result + mod + (is_valid_num1 ? 1:0))%mod;

        return result;
    }
};
