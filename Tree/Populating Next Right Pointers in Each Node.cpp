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
        
        Node*prev = NULL;
        Node*curr = NULL;
        queue<Node*>q;
        
        q.push(root);
        q.push(NULL);
        
        while(q.size()>1)
        {
            
            Node*p = q.front();
            q.pop();
            
            
            
            
            if(prev==NULL)
            {
                prev = p;
                
            }
            
            else{
                Node*curr = p;
                prev->next = p;
                prev = p;
            }
            
            
            if(p==NULL)
            {
                q.push(NULL);
                continue;
            }
            
            if(p->left!=NULL)
            {
                q.push(p->left);
            }
            
            if(p->right!=NULL)
            {
                q.push(p->right);
            }
        }
        
        return root;
    }
};
