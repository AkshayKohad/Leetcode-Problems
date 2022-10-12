/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
     
        if(root==NULL)
            return root;
        queue<Node*>q;
        
        q.push(root);
        
       
        
        while(q.empty()==false)
        {
            
            int size = q.size();
            
           // cout<<size<<endl;
             vector<Node*>a;
            
            while(size--)
            {
             Node*cur = q.front();
            
            q.pop();
            a.push_back(cur);    
                if(cur->left!=NULL)
                {
                    q.push(cur->left);
                }
                
                if(cur->right!=NULL)
                {
                    q.push(cur->right);
                }
            
            }
            
            
            if(a.size()>0)
            {
                
            Node*cur = a[0];
                
                for(int i=1;i<a.size();i++)
                {
                    cur->next = a[i];
                    cur = a[i];
                }
            
            }
            
            
           
        }
        
        return root;
    }
};
