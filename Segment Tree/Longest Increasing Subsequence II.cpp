class Solution {
public:
    
    
    int query(vector<int>&tree,int ss,int se,int& qs,int& qe,int index)
    {
        
        //complete overlap
        if(ss>=qs && se<=qe)
        {
            return tree[index];
        }
        
        
        // No overlap
        
        if(qe<ss || qs>se) 
            return INT_MIN;
        
        // Partial Overlap
        
        int mid = (se+ss)/2;
        
        int left = query(tree,ss,mid,qs,qe,2*index);
        
        int right  = query(tree,mid+1,se,qs,qe,2*index+1);
        
        return max(left,right);
        
    }
    
    
    void update(vector<int>&tree,int ss,int se,int &i,int &change,int index)
    {
        
        if(i>se || i<ss) return;
        
        if(ss==se)
        {
            tree[index] = max(tree[index],change);
            return;
        }
        
        int mid = (ss+se)/2;
        
        update(tree,ss,mid,i,change,2*index);
        
        update(tree,mid+1,se,i,change,2*index+1);
        
        tree[index] = max(tree[2*index],tree[2*index+1]);
        
        return;
    }
    
    
    
    int lengthOfLIS(vector<int>& nums, int k) {
        
        
        int n = nums.size();
        
        
        int m=INT_MIN;
        for(int i=0;i<n;i++)
        {
            m = max(m,nums[i]);
        }
        
        int max_size = m;
        
        m = m+1;
        
        vector<int>tree(4*m+1,0);
        
        vector<int>result(n,0);
        
        int res = 0;
        
        for(int i = n-1;i>=0;i--)
        {
            
            int start = nums[i]+1;
            
            int end = nums[i] + k;
            
            if(start>max_size) start = max_size;
            
            if(end>max_size) end = max_size;
            
          
            int ans = query(tree,0,m-1,start,end,1);
           
            int ans1;
             if(nums[i]!=max_size)
              ans1 = ans+1;
             
            else
                ans1 = 1;
             
             res = max(res,ans1);
            result[i] = ans1;
            update(tree,0,m-1,nums[i],ans1,1);    
        }
        
        // for(int i=0;i<n;i++)
        // {
        //     cout<<result[i]<<" ";
        // }
        // cout<<endl;
        return res;
    }
};
