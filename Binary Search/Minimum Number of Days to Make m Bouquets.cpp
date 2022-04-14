class Solution {
public:
    
    bool check(long long mid,vector<int>bloomDay,int m,int k)
    {
        int count = 0;
        int total = 0;
        
        for(int i=0;i<bloomDay.size();i++)
        {
            if(mid>=bloomDay[i])
            {
             count++;   
            }
            
            else{
                if(count == k)
                {
                    total ++;
                }
                count = 0;
            }
            
            if(count>=k)
            {
                total++;
                count=0;
            }
        }
        
        if(count>=k)
        {
            total++;
        }
        
        if(total>=m)
            return true;
        
        return false;
    }
    
    
    int minDays(vector<int>& bloomDay, int m, int k) {
        
        
        
        if((long long)m*k> (long long)bloomDay.size())
            return -1;
        
        long long l =1;
        
        long long r = *max_element(bloomDay.begin(),bloomDay.end());
        
        while(l<r)
        {
            long long mid = ((long long)l+r)/2;
            
            if(check(mid,bloomDay,m,k))
            {
                r = mid;
            }
            
            else{
                l = mid+1;
            }
            
        }
        
        return l;
    }
};
