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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector <vector<int>> res;
        queue<TreeNode*> q;
        if(root==NULL) {
            return res;
        }
        TreeNode* temp;
        q.push(root);
        while(!q.empty()) {
            int len=q.size();
            vector <int> v;
            for(int i=0;i<len;i++) {
                temp=q.front();
                v.push_back(temp->val);
                q.pop();
                if(temp->left) {
                    q.push(temp->left);
                }
                if(temp->right) {
                    q.push(temp->right);
                }
            }
            res.push_back(v);
        //  res.insert(res.begin(),v);  Without reverse
        }
        reverse(res.begin(),res.end());
        return res;
         
    }
};
