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
    TreeNode* buildTree(vector<int>& in,int inStart,int inEnd,vector<int>& post,int postStart,int postEnd,unordered_map<int,int>& inMap)
    {
        if(inStart>inEnd || postStart>postEnd) return NULL;
        TreeNode* root=new TreeNode(post[postEnd]);
        int inRoot=inMap[post[postEnd]];
        int rootLeft=inRoot-inStart;

        root->left=buildTree(in,inStart,inRoot-1,post,postStart,postStart+rootLeft-1,inMap);
        root->right=buildTree(in,inRoot+1,inEnd,post,postStart+rootLeft,postEnd-1,inMap);

        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size())
            return NULL;
        int n=inorder.size();
        unordered_map<int,int> inMap;
        for(int i=0;i<n;i++)
        {
            inMap[inorder[i]]=i;
        }
        TreeNode* root=buildTree(inorder,0,n-1,postorder,0,n-1,inMap);
        return root; 
    }
};