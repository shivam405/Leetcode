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
    TreeNode* constructBst(vector<int>& preorder,int* index,int key,int min,int max,int n)
    {
        if(*index>=n)
        {
            return NULL;
        }

        TreeNode* root=NULL;
        if(key>min && key<max)
        {
            root=new TreeNode(key);
            *index=*index+1;;

            if(*index<n)
            {
                root->left=constructBst(preorder,index,preorder[*index],min,key,n);
            }
            if(*index<n)
            {
                root->right=constructBst(preorder,index,preorder[*index],key,max,n);
            }

        }

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       int n=preorder.size();
       int idx=0;
       return constructBst(preorder,&idx,preorder[0],INT_MIN,INT_MAX,n); 
    }
};