class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
       
        
        int sum_position_right = 0;
        int sum_position_left = 0;
        int count_ones_right = 0;
        int count_ones_left = 0;
        
        
        
        
        for(int i=0;i<n;i++)
        {
            if(boxes[i]=='1')
            {
                count_ones_right++;
                sum_position_right += i;
            }
        }
        
        vector<int>res(n);
        
        for(int i=0;i<n;i++)
        {
           
                int ans = sum_position_right - count_ones_right*i;
                
                int ans2 = abs(sum_position_left - count_ones_left*i);
            
                    
                     if(boxes[i]=='1')
                     {
                         sum_position_right -= i;
                         sum_position_left += i;
                         
                         count_ones_right--;
                         count_ones_left++;
                     }
            
            res[i] = ans+ans2;
        }
        
        
        return res;
        
        
        
        
    }
};
