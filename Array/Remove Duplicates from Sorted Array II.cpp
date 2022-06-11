class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int count = 1;
        int curr_count =1;
        int i=0;
        int j=1;
        
        while(j<a.size())
        {
            if(a[i]==a[j])
            {
                curr_count++;
                if(curr_count>2)
                {

                    j++;
                   
                }
                else{
                    i++;
                    a[i]=a[j];
                    j++;
                     count++;
                }
               
            }
            
            else{
                curr_count=1;
                i++;
                a[i] = a[j];
                count++;
                j++;
            }
        }
        
        return count;
    }
};
