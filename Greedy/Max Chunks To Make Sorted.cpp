class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
  
    

     int chunks = 1;
     int temp_min = 0;
     int temp_max = arr[0];
     int start_index = 0;
     for(int i=1;i<arr.size();i++)
     {
         if(arr[i]>temp_max)
         {
             if(i-start_index == temp_max-temp_min+1)
             {
                 
                 chunks++;
                 temp_min = temp_max+1;
                 temp_max = max(temp_max+1,arr[i]);
                 start_index = i;
               
             }

             else{
                 temp_max = arr[i];
             }
         }
     } 
     return chunks; 
    }
};
