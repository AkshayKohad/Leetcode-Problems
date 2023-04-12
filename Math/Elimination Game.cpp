class Solution {
public:
    int lastRemaining(int n) {
        
    int head = 1;    
    int steps = 1;
     bool left = true;
   
     while(n>1)
     {
         if(left || n%2==1)
         {
             head = head + steps; 
         }

         steps = steps*2;
         n = n/2;
         left = !left;
     }   

     return head;
    }
};
