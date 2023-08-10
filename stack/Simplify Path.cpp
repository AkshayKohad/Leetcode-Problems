class Solution {
public:
    string simplifyPath(string path) {
        
       stack<string>st;

       st.push("/");
       cout<<st.top()<<endl;
       int n = path.length();
       int i=1;
       
       
        while(i<n)
        {
            string file_directory = "";

            while(i<n && path[i]!='/')
            {
            file_directory.push_back(path[i]);
            i++;
            }
           // cout<<file_directory<<endl;
            if(file_directory!=".." && file_directory!="." && file_directory.length()>0)
            {
            st.push(file_directory);
            if(i<n)
            st.push("/");
            }
         
            else if(file_directory==".")
            {
                // do nothing
            }
            else if(file_directory==".."){
     
                if(st.size()>=3)
                {

                 
                    st.pop();
                    st.pop();
                }
            }
            
            i++;
        }

        string res = "";

        while(st.empty()==false)
        {
            string a = st.top();
            st.pop();

          
             if(a=="/")
            {
                if(res.length()>0)
                res = a + res;

            }
            
            else{
                res = a + res;
            }
        }

        if(res.length()==0)
        return "/";
        
        return res;
    }
};
