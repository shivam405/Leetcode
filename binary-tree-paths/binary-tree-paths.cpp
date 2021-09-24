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
    void getpath(TreeNode* root,vector<string>& res,string str)
    {
        
        if(root)
        {
            if(root->left==NULL && root->right==NULL)
            {
                str+=to_string(root->val);
                res.push_back(str);
                str.pop_back();
                return;
            }
            str+=to_string(root->val);
            str+="->";
            getpath(root->left,res,str);
            getpath(root->right,res,str);
            str.pop_back();        
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root==NULL)
            return res;
        string str="";
        getpath(root,res,str);
        return res;
    }
};