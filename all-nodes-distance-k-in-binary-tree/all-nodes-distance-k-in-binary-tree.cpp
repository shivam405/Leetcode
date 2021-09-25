/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void markParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent_track)
    {
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp->left)
            {
                q.push(temp->left);
                parent_track[temp->left]=temp;
            }
            if(temp->right)
            {
                q.push(temp->right);
                parent_track[temp->right]=temp;
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>parent_track;
        markParent(root,parent_track);
        
        queue<TreeNode*> q;
        unordered_map<TreeNode*,bool> visited;
        q.push(target);
        visited[target]=true;
        int distance=0;
        while(q.size()!=0)
        {
            int size=q.size();
            if(distance==k)
            break;
            distance++;
            for(int i=0;i<size;i++)
            {
               TreeNode* temp=q.front(); 
               q.pop();
               
               if(temp->left && !visited[temp->left])
               {
                   q.push(temp->left);
                   visited[temp->left]=true;
               }
               if(temp->right && !visited[temp->right])
               {
                   q.push(temp->right);
                   visited[temp->right]=true;
               }
               if(parent_track[temp] && !visited[parent_track[temp]])
               {
                   q.push(parent_track[temp]);
                   visited[parent_track[temp]]=true;
               }
               
            }
            
            
        }
        
        vector<int> res;
        while(q.size()!=0)
        {
            res.push_back(q.front()->val);
            q.pop();
        }
        
        return res;
    }
};