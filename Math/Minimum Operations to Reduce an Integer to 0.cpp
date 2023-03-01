class Solution {
public:
    int minOperations(int n) {
     
        // If continuous group of 1's is there add such a number so that all the group of 1's get converted to single 1
        // For eg 7(111) + 1(1) = 8(1000) and that single 1 will be there in next power
        // convert all the grp of 1's into single 1's .  The process of converting into single 1's will take one addition operation 
        // and at last count all the ungrouped 1's from the resultant value to get minimum number of operations as answer
        
        vector<int>binary;
        
        int val = n;
        while(val>0)
        {
            int rem = val%2;
            val = val/2;
            
            binary.push_back(rem);
            
        }
        
        
        int i=0;
        int count=0;
        int carry = 0;
        
        while(i<binary.size())
        {
            
            if(binary[i]==1)
            {
               
                int count_one = 0;
            while(i<binary.size() && binary[i]==1)
            {
                binary[i]=0;
                count_one++;
                i++;
            }
               if(count_one>1)
               {
                   count++;
                   
                if(i<binary.size())
                    binary[i]=1;
                
                
                else{
                    carry = 1;
                  }
               }
                
               else{
                   binary[i-1] = 1;
               } 
            }
            
            else{
                i++;
            }
        }
        
        
        for(i=0;i<binary.size();i++)
        {
        
            if(binary[i]==1) count++;
        }
        
        if(carry==1)
            count++;
        
        return count;
        
        
    }
};
