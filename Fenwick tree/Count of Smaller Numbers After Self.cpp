class Solution {
public:
    
    int query(int i,vector<int>&bit)
    {
        int ans =0;
        while(i>0)
        {
            ans+=bit[i];
            i -= (i&(-i));
        }
        
        return ans;
    }
    
    void update(int i,vector<int>&bit,int val,int n)
    {
        while(i<=n)
        {
            bit[i] = bit[i]+1;
            i += (i&(-i));
        }
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        // using concept of coordinate compression
       set<int>s;
        for(int i=0;i<nums.size();i++)
        {
            s.insert(nums[i]);
        }
        
        unordered_map<int,int>mp;
        
        int count=1;
        for(auto x:s)
        {
            mp[x] = count;
            count++;
        }
        
        vector<int>a;
        for(int i=0;i<nums.size();i++)
        {
            a.push_back(mp[nums[i]]);
        }
        
        int n1 = a.size()+1;
        int n = a.size();
        vector<int>bit(n1,0);
        vector<int>b;
        for(int i=n-1;i>=0;i--)
        {
            b.push_back(query(a[i]-1,bit));
            update(a[i],bit,1,n);
            
        }
        reverse(b.begin(),b.end());
        return b;
        
    }
};
