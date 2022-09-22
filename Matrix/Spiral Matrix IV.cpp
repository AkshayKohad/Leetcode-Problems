/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        vector<vector<int>>matrix(m,vector<int>(n,-1));
        
        
        int top = 0;
        int bottom = m-1;
        
        int left = 0;
        int right = n-1;
        
        
            ListNode*cur = head;
        while(cur!=NULL &&  top<=bottom && left<=right)
        {
            for(int i = left;i<=right;i++)
            {
                if(cur==NULL) break;
                
                matrix[top][i] = cur->val;
                cur = cur->next;
            }
            
            top++;
            
            if(cur==NULL || top>bottom || left>right)
            {
                break;
            }
            
            
            for(int i=top;i<=bottom;i++)
            {
                if(cur==NULL) break;
                
                matrix[i][right] = cur->val;
                cur = cur->next;
            }
            
            right--;
             if(cur==NULL || top>bottom || left>right)
            {
                break;
            }
            
            
            for(int i = right;i>=left;i--)
            {
                if(cur==NULL) break;
                
                matrix[bottom][i] = cur->val;
                cur = cur->next;
            }
            
            bottom--;
            
             if(cur==NULL || top>bottom || left>right)
            {
                break;
            }
            
            
            for(int i=bottom;i>=top;i--)
            {
                 if(cur==NULL) break;
                
                matrix[i][left] = cur->val;
                
                cur = cur->next;
            }
            left++;
            
        }
        
        return matrix;
    }
};
