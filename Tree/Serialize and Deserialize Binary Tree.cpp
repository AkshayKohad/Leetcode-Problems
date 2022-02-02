/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string a;
        if(root==NULL)
            return a;
        queue<TreeNode*>q;
        q.push(root);
        
        
        while(q.empty()==false)
        {
            TreeNode*curr = q.front();
            q.pop();
            if(curr==NULL)
            {
                a.push_back('N');
                a.push_back('S');
                continue;
            }
            
            a = a + to_string(curr->val);
            a.push_back('S');
            
            if(curr->left==NULL)
            {
                q.push(NULL);
            }
            
            else{
                q.push(curr->left);
            }
            
            if(curr->right==NULL)
            {
                q.push(NULL);
            }
            
            else{
                q.push(curr->right);
            }
            
            
        }
     //   cout<<a<<endl;
        return a;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length()==0 || data[0]=='N')
            return NULL;
        int i=0;
        string a;
        while(i<data.length())
        {
            if(data[i]=='S')
            {
                i++;
                break;
                
            }
            a.push_back(data[i]);
            i++;
        }
        int x = stoi(a);
        TreeNode*head = new TreeNode(x);
        a.clear();
        queue<TreeNode*>q;
        q.push(head);
        
        
        while(i<data.length())
        {
            TreeNode*curr = q.front();
            q.pop();
            while(i<data.length())
            {
                if(data[i]=='S')
                {
                    i++;
                    break;
                }
                a.push_back(data[i]);
                i++;
            }
            
            if(a!="N")
            {
                int x = stoi(a);
                TreeNode*l = new TreeNode(x);
                curr->left = l;
                q.push(l);
                
            }
            
            a.clear();
            
             while(i<data.length())
            {
                if(data[i]=='S')
                {
                    i++;
                    break;
                }
                a.push_back(data[i]);
                 i++;
            }
            
            
             if(a!="N")
            {
                int x = stoi(a);
                TreeNode*r = new TreeNode(x);
                curr->right = r;
                 q.push(r);
                
            }
            a.clear();
        }
        return head;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
