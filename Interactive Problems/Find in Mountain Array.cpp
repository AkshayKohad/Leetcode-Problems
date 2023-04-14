/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int n = mountainArr.length();

        int l = 0;
        int r = n-1;
         
        int mountain_val = -1; 
        int mountain_index = -1;
        while(l<=r)
        {
            int mid = (l+r)/2;

            if(mid==0)
            {
                l = mid+1;
            }

            else if(mid==n-1)
            {
                r = mid-1;
            }

            else{

                int val = mountainArr.get(mid);
                int val_prev = mountainArr.get(mid-1);
                int val_next = mountainArr.get(mid+1);

                if(val>val_prev && val>val_next)
                {
                    mountain_index = mid;
                    mountain_val = val;
                    break;
                }

                else if(val<val_prev)
                {
                    r = mid-1;
                }

                else if(val<val_next)
                {
                    l = mid+1;
                }

            }
        }
 
         // cout<<mountain_index<<endl;
          if(mountain_val < target)
          return -1;

          if(mountain_val == target)
          return mountain_index;

          int first_val = mountainArr.get(0);
          int last_val = mountainArr.get(n-1);

         
              int low = 0;
              int high = mountain_index;
              
              int answer = -1;
              while(low<=high)
              {
                int mid = (low+high)/2;
                int temp_val = mountainArr.get(mid);

                if(temp_val==target)
                {
                    answer = mid;
                    high = mid-1;
                }
                else if(temp_val<target)
                {
                    low = mid+1;
                }
                else if(temp_val>target)
                {
                    high = mid-1;
                }
              }
              if(answer!=-1)
              return answer;
            
          

          
           low = mountain_index;
           high = n-1;
         //cout<<low<<" "<<high<<endl;
            answer = -1;
              while(low<=high)
              {
                int mid = (low+high)/2;
                int temp_val = mountainArr.get(mid);

                if(temp_val==target)
                {
                    answer = mid;
                    high = mid-1;
                }
                else if(temp_val<target)
                {
                    high = mid-1;
                }
                else if(temp_val>target)
                {
                    low = mid+1;
                }  

          }
           if(answer!=-1)
              return answer;

          return -1;
        
    }
};
