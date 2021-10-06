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
    TreeNode* convertIntoBST(vector<int>& nums,int sidx,int eidx)
    {
        if(sidx>eidx)
        return NULL;
        int mid=(sidx+eidx)/2;
        TreeNode* root=new TreeNode(nums[mid]);
        root->left=convertIntoBST(nums,sidx,mid-1);
        root->right=convertIntoBST(nums,mid+1,eidx);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return convertIntoBST(nums,0,nums.size()-1); 
    }
};