class Solution {
public:

   int find(int i,vector<int>&parent)
   {
       if(parent[i]==-1)
       return i;

       return parent[i] = find(parent[i],parent);
   }

   void unite(int par,int par2,vector<int>&parent,vector<int>&rank)
   {
         if(rank[par]>=rank[par2])
         {
             parent[par2] = par;
             rank[par] += rank[par2];
         }
         else{
             parent[par] = par2;
             rank[par2] += rank[par];   
         }
   }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n = accounts.size();

        map<string,int>mp;

        vector<int>parent(n,-1);
        vector<int>rank(n,1);

       

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<accounts[i].size();j++)
            {
                if(j==0)continue;

                if(mp.find(accounts[i][j])!=mp.end())
                {
                    int val = mp[accounts[i][j]];
                   int par = find(val,parent);
                   int par2 = find(i,parent);

                   if(par!=par2)
                   {
                       unite(par,par2,parent,rank);
                   }   
                }
                else{
                   mp.insert({accounts[i][j],i});
                }
            }
        }
        
         map<int,set<string>>email;
        map<int,set<string>>name;
        vector<vector<string>>res;

        for(int i=0;i<n;i++)
        {
            int par = find(i,parent);

            string nm = accounts[i][0];
             name[par].insert(nm);

            for(int j=1;j<accounts[i].size();j++)
            {
                email[par].insert(accounts[i][j]);
            }
            
        }

        for(int i=0;i<n;i++)
        {
            if(parent[i]==-1)
            {
                vector<string>ans;
                string nm = *(name[i].begin());
                ans.push_back(nm);

                for(auto em : email[i])
                {
                    ans.push_back(em);
                }

                res.push_back(ans);
            }
        }

        return res;
    }
};
