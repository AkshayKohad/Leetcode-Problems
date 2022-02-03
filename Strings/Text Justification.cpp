class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        
        vector<string>b;
        for(int i=0;i<words.size();)
        {
            int j=0;
            int res=0;
            while(j+i<words.size())
            {
                if(res+words[i+j].length()+j>maxWidth)
                {
                    int ans = maxWidth - res;
                  //  cout<<ans<<endl;
                  //  cout<<j<<endl;
                    int spaces;
                    int remain;
                   if(j!=1)
                   {
                     spaces = ans/(j-1);
                     remain = ans%(j-1);
                   }
                    
                    else{
                        spaces = ans/(j);
                     remain = ans%(j);
                    }
                 //   cout<<spaces<<endl;
                   // cout<<remain<<endl;
                     //cout<<endl;
                    string even_spaces;
                    string odd_spaces;
                    
                    for(int k=0;k<spaces;k++)
                        even_spaces += " ";
                    
                    if(remain!=0)
                    {
                    for(int k=0;k<remain;k++)
                        odd_spaces += " ";
                    }
                    
                    else{
                        odd_spaces = even_spaces;
                    }
                    
                    string a;
                    if(j!=1)
                    {
                    a += words[i];
                    for(int k=i+1;k<i+j;k++)
                    {
                        if(remain==0)
                        {
                            a += even_spaces;
                            a += words[k];
                        }
                        
                        else{
                            a += even_spaces;
                            a += " ";
                            remain--;
                            a += words[k];
                        }
                    }
                    }
                    
                    else{
                        a += words[i];
                        a += even_spaces;
                    }
                    b.push_back(a);
                    res=0;
                    i = j+i;
                    j=0;
                }
                res = res + words[j+i].length();
               // cout<<res<<endl;
                j++;
            }
            //cout<<j<<endl;
            int ans = maxWidth - res -( j-1);
           // cout<<ans<<endl;
            string a;
            
            for(int k = i;k<i+j;k++)
            {
                if(k<i+j-1)
                {
                a += words[k];
                a += " ";
                }
                
                else{
                    a += words[k];
                }
            }
            
            for(int k=0;k<ans;k++)
            {
                 a += " ";
            }
            
            b.push_back(a);
            break;
        }
        
        return b;
    }
};
