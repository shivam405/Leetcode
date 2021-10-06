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
    bool isBST(TreeNode* root,TreeNode* min,TreeNode* max)
    {
        if(root==NULL)
            return true;
        if(min!=NULL && root->val<=min->val)
        {
            return false;
        }
        if(max!=NULL && root->val>=max->val)
        {
            return false;
        }
        bool left=isBST(root->left,min,root);
        bool right=isBST(root->right,root,max);
        return left && right;
    }
public:
    bool isValidBST(TreeNode* root) {
       return isBST(root,NULL,NULL); 
    }
};