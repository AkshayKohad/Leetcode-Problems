class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        map<string,vector<string>>mp;
        
        
        for(int i=0;i<paths.size();i++)
        {
           int j=0;
            int n = paths[i].length();
            string root;
            
            while(j<n && paths[i][j]!=' ')
            {
                root.push_back(paths[i][j]);
                j++;
            }
            
            j++;
            while(j<n)
            {
            string val;
            while(j<n && paths[i][j]!='(')
            {
                val.push_back(paths[i][j]);
                j++;
            }
            
            
            
            string key;
            j++;
            while(j<n && paths[i][j]!=')')
            {
                key.push_back(paths[i][j]);
                j++;
            }
               j++;
                if(j<n && paths[i][j]==' ') j++;
            
                cout<<key<<"->"<<val<<endl;
            mp[key].push_back(root +"/"+val);
                
        }   
        }
        
        vector<vector<string>>res;
        
        for(auto k:mp)
        {
            vector<string>t;
            if(k.second.size()<=1)continue;
            for(auto u:k.second)
            {
                t.push_back(u);
            }
            
            res.push_back(t);
        }
        
        return res;
    }
};
