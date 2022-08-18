class Solution {
public:
    
     int countNonRepeatedDigits(int n) {
        
        string t = to_string(n);
        
        int size = t.length();
        
        int ans = 0;
        int x = 1;
        int k = 9;
        bool flag = false;
        for(int i=1;i<size;i++)
        {
            if(!flag)
            {
                x *= 9;
                flag=true;
            }
            
            else{
                x *= k;
                k--;
                
                
            }
            
            ans += x;
        }
        
        
        vector<int>used(10,0);
        
        for(int i=0;i<size;i++)
        {
            int small = 0;
            
            int w = t[i] - '0';
            for(int j=w-1;j>=0;j--)
            {
                if(!used[j])
                small++;
            }
            
            if(i==0)
                small--;
            
            int next = 1;
            
            int remaining = 10-i-1;
            for(int j = i+1;j<size;j++)
            {
                next *= remaining;
                remaining--;
            }
            
            
            ans += next*small;
            
            
            if(!used[t[i]-'0']) used[t[i]-'0'] = 1;
            
            
            else break;
            
        }
        
        unordered_set<int>s;
        
        flag = true;
        for(int i=0;i<size;i++)
        {
            if(s.find(t[i]) != s.end())
            {
                flag = false;
                break;
            }
            
            s.insert(t[i]);
        }
        
        
        if(flag) ans++;
        
        
        return ans;
    }
    
    
    int numDupDigitsAtMostN(int n) {
        
        // ans is count of non repeating digits
        int ans = countNonRepeatedDigits(n);
        
        
        // so total repeating digits will be n-ans
        return n-ans;
    }
};
