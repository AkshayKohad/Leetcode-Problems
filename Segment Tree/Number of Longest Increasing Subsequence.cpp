class Solution {
public:

  pair<int,int>choose_max(pair<int,int>left,pair<int,int>right)
  {
      int max_len_left = left.first;
      int max_ways_left = left.second;

      int max_len_right = right.first;
      int max_ways_right = right.second;

      if(max_len_left>max_len_right)
      {
          return left;
      }
      else if(max_len_left<max_len_right)
      {
          return right;
      }
      else{
       return {max_len_left,max_ways_left+max_ways_right};
      }

      return {0,0};
  }

  pair<int,int>maximum_LIS_range(vector<pair<int,int>>&tree,int ss,int se,int qs,int qe,int index)
  {

    if(ss>=qs && se<=qe)
      return tree[index];

    if(ss>qe || se<qs)
      return {0,0};
 
    int mid = (se+ss)/2;

    pair<int,int>left = maximum_LIS_range(tree,ss,mid,qs,qe,2*index+1);
    pair<int,int>right = maximum_LIS_range(tree,mid+1,se,qs,qe,2*index+2);

    return choose_max(left,right);
      
  }

  void update(vector<pair<int,int>>&tree,int ss,int se,int index,int& ele,int& max_len,int& max_ways)
  {
      if(ss==se)
      {
          if(tree[index].first==max_len)
          {
              tree[index].second += max_ways;
          }
          else{
              tree[index].first=max_len;
              tree[index].second=max_ways;
          }

          return;
      }

      int mid = (se+ss)/2;

      if(ele<=mid)
      {
        update(tree,ss,mid,2*index+1,ele,max_len,max_ways);
      }
      else{
        update(tree,mid+1,se,2*index+2,ele,max_len,max_ways);
      }

      tree[index] = choose_max(tree[2*index+1],tree[2*index+2]);
  }
    int findNumberOfLIS(vector<int>& nums) {
        
        unordered_map<int,int>mp;
        vector<int>temp = nums;

        sort(temp.begin(),temp.end());

        int mx=0;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            if(mp.find(temp[i])==mp.end())
            {
              mp[temp[i]] = mx;
              mx++;
            }
            
        }

        for(int i=0;i<n;i++)
        {
            nums[i] = mp[nums[i]];
           
        }
    

    
      vector<pair<int,int>>tree(4*mx+1,{0,0});

      for(int i=0;i<n;i++)
      {
          int max_len=1;
          int ways = 1;

          if(nums[i]>0)
          {
             pair<int,int>cur = maximum_LIS_range(tree,0,mx,0,nums[i]-1,0);

             if(cur.first+1 > max_len)
             {
                 max_len = cur.first+1;
                 ways = cur.second;
             }
          }

          update(tree,0,mx,0,nums[i],max_len,ways);
      }
        
        return tree[0].second;

    }
};
