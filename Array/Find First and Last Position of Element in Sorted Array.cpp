class Solution {
public:
    vector<int> searchRange(vector<int>& n, int target) {
          vector<int>a;
        if(n.size()==0)
        {
            a.push_back(-1);
              a.push_back(-1);
            return a;
        }
        
        sort(n.begin(),n.end());
        int i=0,j=n.size()-1;
        while(n[i]!=target )
        {
             i++;
            if(i==n.size())
            {
                i=-1;
                break;
            }
           
        }
        while(n[j]!=target)
        {
            j--;
            if(j==-1)
            {
                break;
            }
        }
      
        a.push_back(i);
        a.push_back(j);
        return a;
        
    }
};
