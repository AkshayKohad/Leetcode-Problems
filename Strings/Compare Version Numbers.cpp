class Solution {
public:
    int compareVersion(string version1, string version2) {
         
        int i=0;
        int j=0;
        int n = version1.length();
        int m = version2.length();
        
        while(i<n && j<m)
        {
            int flag=0;
            string s;
            while(i<n && version1[i]!='.')
            {
                
                if(version1[i]=='0')
                {
                    
                if(flag!=0)
                {
                   s.push_back(version1[i]); 
                }
                    
                    
                    
                }
                
                else{
                    flag=1;
                    
                    s.push_back(version1[i]);
                }
                
                i++;
            }
            
            string t;
            flag=0;
            while(j<m && version2[j]!='.')
            {
               if(version2[j]=='0')
                {
                    
                if(flag!=0)
                {
                   t.push_back(version2[j]); 
                }
                    
                    
                    
                }
                
                else{
                    flag=1;
                    
                    t.push_back(version2[j]);
                }
                
                j++;
            }
            
            if(s.length()==t.length())
            {
            if(s>t)
                return 1;
            
            else if(s<t)
                return -1;
                
            }    
            
            else if(s.length()>t.length())
            {
                return 1;
            }
            
            else if(s.length()<t.length())
            {
                return -1;
            }
            
            i++;
            j++;
        }
       
        
        
         while(i<n)
        {
            int flag=0;
            string s;
            while(i<n && version1[i]!='.')
            {
                
                if(version1[i]=='0')
                {
                    
                if(flag!=0)
                {
                   s.push_back(version1[i]); 
                }
                    
                    
                    
                }
                
                else{
                    flag=1;
                    
                    s.push_back(version1[i]);
                }
                
                i++;
            }
            
            if(s.length()>0)
                return 1;
             
            i++;
            
        }
       
        
         while(j<m)
        {
            
            string t;
            int flag=0;
            while(j<m && version2[j]!='.')
            {
               if(version2[j]=='0')
                {
                    
                if(flag!=0)
                {
                   t.push_back(version2[j]); 
                }
                    
                    
                    
                }
                
                else{
                    flag=1;
                    
                    t.push_back(version2[j]);
                }
                
                j++;
            }
              
            
          if(t.length()>0)
              return -1;
            j++;
        }
       
        
        
        return 0;
        
    }
};
