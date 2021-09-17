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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
         queue<pair<TreeNode*,pair<int,int>> > q;
        map<int,map<int,multiset<int>>> mp;
        q.push({root,{0,0}});
        while(q.size()!=0)
        {
               TreeNode* temp=q.front().first;
                int x=q.front().second.first;
                int y=q.front().second.second;
                mp[x][y].insert(temp->val);
                q.pop();
                if(temp->left)
                {
                    q.push({temp->left,{x-1,y+1}});
                }
                if(temp->right)
                {
                    q.push({temp->right,{x+1,y+1}});
                }
            
        }
        
        
        vector<vector<int> > res;
        
        for(auto &pr:mp)
        {
             vector<int> ans;
            for(auto &pr2:pr.second)
            {
                for(auto i:pr2.second)
                {
                    ans.push_back(i);
                }
            }
            res.push_back(ans);
        }
        return res;
        
        
    }
};