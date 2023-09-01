class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {

    vector<pair<int,int>>water_range;

    for(int i=0;i<ranges.size();i++)
    {
        water_range.push_back(make_pair(max(i-ranges[i],0),i+ranges[i]));
    }    

     sort(water_range.begin(),water_range.end());

     int mini = 0;
     int maxi = 0;
     int i=0;
     int open_taps = 0;

     while(maxi<n)
     {
         int flag=0;
          
         while(i<=n)
         {
             if(mini>=water_range[i].first)
             {
                 flag=1;
                 maxi = max(water_range[i].second,maxi);
                 i++;
             }

             else{
               break;
             }
             
         } 
           

         if(flag==0)
         return-1;

         mini = maxi;
         open_taps++;
     } 

     return open_taps;
    }
};
