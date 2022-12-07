class Solution {
public:

    #define MOD 1000000007
    void solve_layer(int i,int &m,vector<vector<int>>&layers,vector<int>&layer)
    {
        if(i==m)
        {
            layers.push_back(layer);
            return;
        }

        if(i==0)
        {
            layer.push_back(1);
           solve_layer(i+1,m,layers,layer);
           layer.pop_back();
  
          layer.push_back(2);
           solve_layer(i+1,m,layers,layer);
           layer.pop_back();

           layer.push_back(3);
           solve_layer(i+1,m,layers,layer);
           layer.pop_back();

        }

        else{

            if(layer.back()!=1)
            {
               layer.push_back(1);
               solve_layer(i+1,m,layers,layer);
               layer.pop_back();
            }

            if(layer.back()!=2)
            {
               layer.push_back(2);
               solve_layer(i+1,m,layers,layer);
               layer.pop_back();
            }

            if(layer.back()!=3)
            {
               layer.push_back(3);
               solve_layer(i+1,m,layers,layer);
               layer.pop_back();
            }

        }

    }

     bool check(int cur_index,int next_index,vector<vector<int>>&layers)
     {
         int size = layers[cur_index].size();
             for(int i=0;i<size;i++)
             {
                 if(layers[cur_index][i] == layers[next_index][i])
                 {
                     return false;
                 }
             }

             return true;
     }

     int solve(int i,int &n,vector<vector<int>>&layers,int layer_index,unordered_map<int,unordered_map<int,int>>&memo)
     {
         if(i==n)
         {
             return 1;
         }
  
         if(memo[i][layer_index])
         return memo[i][layer_index];

         int res = 0;


         for(int j=0;j<layers.size();j++)
         {
             if(layer_index==-1)
             {
                res = (res + solve(i+1,n,layers,j,memo))%MOD;
             }

             else{
                 
                 if(check(layer_index,j,layers))
                 {
                     res = (res + solve(i+1,n,layers,j,memo))%MOD;
                 }
             }
         }

        return memo[i][layer_index] = res;
     }
    int colorTheGrid(int m, int n) {
        
        vector<vector<int>>layers;
           vector<int>layer;

           // solve_layer to get all the possible permutation layer for each row

        solve_layer(0,m,layers,layer);
          
          if(n==1)
          return layers.size();

         
          unordered_map<int,unordered_map<int,int>>memo;
       
       return solve(0,n,layers,-1,memo);
          
    }
};
