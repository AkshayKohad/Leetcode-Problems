class Solution {
public:
    
    static bool mycmp(vector<int>f,vector<int>s)
    {
        if(f[1]==s[1])
            return f[0]<s[0];
        
        return f[1]<s[1];
    }
    
    
    int findMinimumTime(vector<vector<int>>& tasks) {
     
        vector<int>total_on_time(2001,0);
        
        sort(tasks.begin(),tasks.end(),mycmp);
        
        int n = tasks.size();
        
        int dur = tasks[0][2];
        for(int i=tasks[0][1];i>=tasks[0][0];i--)
        {
            if(dur>0)
            {
            total_on_time[i]=1;
                dur--;
            }
            else{
                break;
            }
        }
        
        for(int i=1;i<n;i++)
        {
            int start = tasks[i][0];
            int end = tasks[i][1];
            int duration = tasks[i][2];
            
            for(int j=start;j<=end;j++)
            {
                if(total_on_time[j]==1 && duration>0)
                    duration--;
            }
            
            if(duration>0)
            {
                for(int j=end;j>=start;j--)
                {
                    if(duration>0)
                    {
                        if(total_on_time[j]==0)
                        {
                        total_on_time[j]=1;
                        duration--;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
            
        }
        
        int result = 0;
        
        for(int i=0;i<=2000;i++)
        {
            if(total_on_time[i]==1)
                result++;
        }
        return result;
    }
};
