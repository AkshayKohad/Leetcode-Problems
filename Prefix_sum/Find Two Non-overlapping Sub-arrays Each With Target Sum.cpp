
     int n = arr.size();
     vector<int>left(n);
     vector<int>right(n);
     unordered_map<int,int>mp;
     mp[0] = -1;
     int pref_sum = 0;
     int len = INT_MAX;
     for(int i=0;i<n;i++)
     {
         pref_sum +=arr[i];

         if(mp.find(pref_sum-target)!=mp.end())
         {
             len = min(len,i-mp[pref_sum-target]);
         } 

         mp[pref_sum] = i;
         left[i] = len;
     }   

     mp.clear();
     pref_sum = 0;
     len = INT_MAX;
     
     mp[0]=n;
     for(int i=n-1;i>=0;i--)
     {
         pref_sum +=arr[i];

         if(mp.find(pref_sum-target)!=mp.end())
         {
             len = min(len,mp[pref_sum-target]-i);
         } 

         mp[pref_sum] = i;
         right[i] = len;
     } 
 int result =INT_MAX;
     for(int i=1;i<n;i++)
     {
         if(left[i-1]==INT_MAX || right[i]==INT_MAX)continue;
 
         result = min(result,left[i-1]+right[i]);

     }

     if(result==INT_MAX)return -1;
     return result;
