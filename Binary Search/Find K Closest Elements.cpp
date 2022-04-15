class Solution {
public:
    int binary_search(vector<int>a,int x)
    {
        int l=0;
        int r = a.size()-1;
        int mid;
        while(l<r)
        {
            mid = (l+r)/2;
            
            if(a[mid]==x)
                return mid;
            
            else if(a[mid]>x)
            {
                r = mid-1;
            }
            
            else{
                l = mid+1;
            }
        }
        
        return l;
    }
    
    
    vector<int> findClosestElements(vector<int>& a, int k, int x) {
     
    int n = a.size();
        vector<int>res;
        if(x<a[0])
        {
            for(int i=0;i<k;i++)
            {
                res.push_back(a[i]);
                
            }
            return res;
        }
        
        else if(x>a[n-1])
        {
          for(int i=n-k;i<n;i++)
          {
              res.push_back(a[i]);
            
          }
              return res;
        }
        
        else{
           int index = binary_search(a,x);
           cout<<index<<endl;
               int start;
            int end;
            if(a[index]==x)
            {
                int count =1;
                start = index-1;
                end = index+1;
                
                while(count!=k)
                {
                    int flag_s = 0;
                    int flag_e = 0;
                    if(start>=0)
                    {
                       flag_s=1;
                    }
                    
                    if(end<n)
                    {
                        flag_e =1;
                    }
                    
                    if(flag_s ==1 && flag_e ==1)
                    {
                        // if(abs(x-a[start]) == abs(x-a[end]))
                        // {
                        //     count += 2;
                        //     start--;
                        //     end++;
                        // }
                        
                        if(abs(x-a[start]) > abs(x-a[end]))
                        {
                            count++;
                            end++;
                        }
                        
                        else if(abs(x-a[start]) <= abs(x-a[end]))
                        {
                            count++;
                            start--;
                        }
                    }
                    
                    else if(flag_s==1)
                    {
                        count++;
                        start--;
                    }
                    
                    
                    else if(flag_e==1)
                    {
                        count++;
                        end++;
                     }
                    
                }
                
            }
            
            else{
               int  count = 0;
                if(a[index]>x)
                {
                    start = index-1;
                    end = index;
                }
                
                else if(a[index]<x)
                {
                     start = index;
                    end = index+1;
                }
                
                  while(count!=k)
                {
                    int flag_s = 0;
                    int flag_e = 0;
                    if(start>=0)
                    {
                       flag_s=1;
                    }
                    
                    if(end<n)
                    {
                        flag_e =1;
                    }
                    
                    if(flag_s ==1 && flag_e ==1)
                    {
                        // if(abs(x-a[start]) == abs(x-a[end]))
                        // {
                        //     count += 2;
                        //     start--;
                        //     end++;
                        // }
                        
                        if(abs(x-a[start]) > abs(x-a[end]))
                        {
                            count++;
                            end++;
                        }
                        
                        else if(abs(x-a[start]) <= abs(x-a[end]))
                        {
                            count++;
                            start--;
                        }
                    }
                    
                    else if(flag_s==1)
                    {
                        count++;
                        start--;
                    }
                    
                    
                    else if(flag_e==1)
                    {
                        count++;
                        end++;
                     }
                    
                }
              
                   
            }
            
            for(int j=start+1;j<end;j++)
            {
                res.push_back(a[j]);
            }
            
            return res;
        }
        return a;
    }
};
