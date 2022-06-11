class Solution {
public:
    int removeDuplicates(vector<int>& a) {
        int count=1;
        int i=0;
        int j=1;
        
        while(j<a.size())
        {
            if(a[i]==a[j])
                j++;
            
            else{
                count++;
                i++;
                a[i] = a[j];
                j++;
            }
        }
        
        return count;
    }
};
