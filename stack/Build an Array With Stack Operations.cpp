class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        
        vector<int>ans;
        
        int count=1;
        for(int i=0;i<target.size();i++)
        {
            while(target[i]!=count)
            {
                 ans.push_back(1); 
                ans.push_back(0);
                count++;
                
            }
            
            ans.push_back(1);
            count++;
        }
        
        vector<string>res;
        
        for(int i=0;i<ans.size();i++)
        {
            if(ans[i]==1)
            {
                res.push_back("Push");
            }
            
            else{
                res.push_back("Pop");
            }
        }
        
        
        return res;
    }
};
