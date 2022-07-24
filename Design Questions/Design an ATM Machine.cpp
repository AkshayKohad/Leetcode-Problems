class ATM {
public:
    long long count[5];
    long long value[5];
    ATM() {
        value[0] = 20;
        value[1] = 50;
        value[2] = 100;
        value[3] = 200;
        value[4] = 500;
        
        count[0] = 0;
        count[1] = 0;
        count[2] = 0;
        count[3] = 0;
        count[4] = 0;
            
    }
    
    
    
    void deposit(vector<int> banknotesCount) {
        for(int i=0;i<banknotesCount.size();i++)
        {
            count[i] = count[i] + banknotesCount[i];
        }
    }
    
    vector<int> withdraw(int amount) {
        vector<int>a(5,0);
        
        long long available = 0;
        long long  c;
        long long index;
        for(int i=4;i>=0;i--)
        {
            if(count[i]>0)
            {
                available = value[i];
                c = count[i];
                index = i;
                break;
            }
        }
        
        if(available==0)
        {
            return {-1};
        }
        
        else{
            long long k = c;
            
            long long divi = amount/available;
           // int reminder;
            if(divi<=c)
            {
                amount -= divi*available;
                a[index] = divi;
                //count[index] -= divi;
            }
            
            else{
                amount -= c*available;
                a[index] = c;
                
               // count[index] -= c;
            }
            
            
            
            if(amount ==0)
            {
                for(int i=0;i<5;i++)
                {
                    count[i] -= a[i];
                }
                return a;
            }
            
            
            for(int j = index-1;j>=0;j--)
            {
                divi = amount/value[j];
                
                if(divi <= count[j])
                {
                    amount -= divi*value[j];
                    a[j] = divi;
                   // count[j] -= divi;
                }
                
                else{
                    amount -= count[j]*value[j];
                    a[j] = count[j];
                   // count[j] -= count[j];
                }
                
                if(amount==0)
                {
                for(int i=0;i<5;i++)
                {
                    count[i] -= a[i];
                }
                    return a;
                }
            }
            
            if(amount!=0)
                return {-1};
            
           
            
            
//             while(amount>=available && k>0)
//             {
//                 amount = amount - available;
//                 k--;
//             }
            
//             if(amount==0)
//             {

//             a[index] = c-k;
//                 value[index] -= c-k;
//             return a;
//             }
            
//             else{
//                 for(index)
//             }
        }
         return a;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
