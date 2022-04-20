class Solution {
public:
    
    class Binary_Trie{
      public:
        Binary_Trie*left;
        Binary_Trie*right;
        
        Binary_Trie()
        {
            left = NULL;
            right = NULL;
        }
    };
    
    
    int find_max(Binary_Trie*head,int val)
    {
             int max_ans = 0;   
              Binary_Trie* p = head;
        
        
        for(int i=31;i>=0;i--)
        {
            if(((val>>i)&1) == 1)
            {
                if(p->left==NULL)
                {
                p=p->right;
                }
                
                else{
                    p=p->left;
                    max_ans += pow(2,i);
                }
            }
            
            else{
                 if(p->right==NULL)
                {
                   p=p->left;
                 }
                
                else{
                    p=p->right;
                     max_ans += pow(2,i);
                }
            }
        }
        
        return max_ans;
        
        
    }
    
    void insert(Binary_Trie*head,int val)
    {

        Binary_Trie* p = head;

        for(int i=31;i>=0;i--)
        {
            if(((val>>i)&1) == 1)
            {
                if(p->right==NULL)
                {
                Binary_Trie* make_new = new Binary_Trie;
                p->right = make_new;
                p=make_new;
                }
                
                else{
                    p=p->right;
                }
            }
            
            else{
                 if(p->left==NULL)
                {
                Binary_Trie* make_new = new Binary_Trie;
                p->left = make_new;
                p=make_new;
                 }
                
                else{
                    p=p->left;
                }
            }
        }
        
        

    }
    
    int findMaximumXOR(vector<int>& nums) {
        
        int n = nums.size();
        if(n==1)
            return 0;
        
        if(n==2)
            return nums[0]^nums[1];
        
        Binary_Trie* head = new Binary_Trie;
        
        int res = 0;
        
        insert(head,nums[0]);
        
        for(int i=1;i<n;i++)
        {
           res = max(res,find_max(head,nums[i]));
            
            insert(head,nums[i]);
        }
        
        
        return res;
        
        
        return 0;
    }
};
