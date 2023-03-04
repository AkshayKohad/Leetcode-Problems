class Solution {
public:

   vector<int>solve(string expression)
   {
       
       vector<int>ans;

       for(int i=0;i<expression.length();i++)
       {
           if(expression[i]=='+' || expression[i]=='-' || expression[i]=='*')
           {
               vector<int>left = solve(expression.substr(0,i));
               vector<int>right = solve(expression.substr(i+1));

               for(int j=0;j<left.size();j++)
               {
                   for(int k=0;k<right.size();k++)
                   {
                       if(expression[i]=='+')
                       {
                           ans.push_back(left[j]+right[k]);

                       }

                       else if(expression[i]=='-')
                       {
                           ans.push_back(left[j]-right[k]);
                       }

                       else if(expression[i]=='*')
                       {
                           ans.push_back(left[j]*right[k]);
                       }
                   }
               }
           }
       }

       if(ans.size()==0)
       ans.push_back(stoi(expression));

       return ans;
   }
    vector<int> diffWaysToCompute(string expression) {
        
      return  solve(expression);
     

    }
};
