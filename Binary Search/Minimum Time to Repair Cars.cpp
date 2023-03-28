class Solution {
public:
    
    bool check(long long minutes,vector<int>&ranks,int cars)
    {
        int cars_count = 0;
        
        for(int i=0;i<ranks.size();i++)
        {
            long long temp_cars = sqrt(minutes/ranks[i]);
            
            cars_count += temp_cars;
            
            if(cars_count>=cars)
                return true;
            
            
        }
        
        return false;
    }
    long long repairCars(vector<int>& ranks, int cars) {
     
        int n = ranks.size();
        
        if(n==1)
            return (long long)ranks[0]*cars*cars;
        
        
        sort(ranks.begin(),ranks.end());
        
        
        
        long long r = (long long) ranks[n-1]*cars*cars;
        
        long long l = 1;
        
        long long ans;
        while(l<=r)
        {
            long long mid = (l+r)/2;
            
            if(check(mid,ranks,cars))
            {
                ans = mid;
                r = mid-1;
            }
            
            else{
                l = mid+1;
            }
        }
        
        return ans;
    }
};
