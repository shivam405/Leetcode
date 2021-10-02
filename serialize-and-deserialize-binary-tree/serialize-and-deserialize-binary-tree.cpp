/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
           return "";
        string str="";
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0)
        {
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL)
                str.append("#,");
            else
                str.append(to_string(temp->val)+',');
            if(temp!=NULL)
            {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return NULL;
        stringstream s(data);
        string ch;
        getline(s,ch,',');
        TreeNode* root=new TreeNode(stoi(ch));
        
        queue<TreeNode*> q;
        q.push(root);
        while(q.size()!=0)
        {
            TreeNode* temp=q.front();
            q.pop();
            
            getline(s,ch,',');
            if(ch=="#")
            {
                temp->left=NULL;
            }
            else
            {
                TreeNode* rleft=new TreeNode(stoi(ch));
                temp->left=rleft;
                q.push(rleft);
            }
            
            getline(s,ch,',');
            if(ch=="#")
            {
                temp->right=NULL;
            }
            else
            {
                TreeNode* rRight=new TreeNode(stoi(ch));
                temp->right=rRight;
                q.push(rRight);
            }
            
        }
        return root;   
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));