/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
        {
            return 0;
        }
        queue<TreeNode* > q;
        root->val=0;
        q.push(root);
       
        int max_width=0;
        while(!q.empty())
        {    max_width=max(max_width,q.back()->val-q.front()->val+1);
           
            if(q.size()==1)
            {
                q.front()->val=0;
            }
            q.push(NULL);
            while(q.front())
            {
                TreeNode* par=q.front();
                q.pop();
                int par_val=par->val;
                if(par->left)
                {
                    par->left->val=(2*par_val+1);
                    q.push(par->left);
                }
                if(par->right)
                {
                    par->right->val=(2*par_val+2);
                    q.push(par->right);
                }

            }
          q.pop();
          
        }
      return max_width;
    }
};
