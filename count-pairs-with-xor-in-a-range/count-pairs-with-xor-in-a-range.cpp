class Solution {
public:
    struct Node
{
    Node *left=NULL;
    Node *right=NULL;
    int count = 0;
};

int query(Node *root,int x, int k)
{
   int ans = 0;
        for(int i=31; i>=0; i--)
        {
            int xdig = (x >> i) & 1;
            int kdig = (k >> i) & 1;
            if(kdig)
            {
                if(xdig)
                {
                    if(root->right)
                        ans = ans + root->right->count;
                    
                    if(root->left)
                        root = root->left;
                    else return ans;
                }
                
                if(xdig == 0)
                {
                    if(root->left)
                        ans = ans + root->left->count;
                    
                    if(root->right)
                        root = root->right;
                    else return ans;
                }   
            }
            else
            {
                if(xdig == 0 && root->left)
                    root = root->left;
                else if(xdig && root->right)
                    root = root->right;
                else return ans;
                    
            }
        }
        return ans;
}
void insert(Node *root, int val)
{
    for (int i = 31; i >= 0; i--)
    {
        if ((val >> i) & 1)
        {
            if (root->right == NULL)
            {
                root->right = new Node();
            }
            root = root->right;
        }
        else
        {

            if (root->left == NULL)
            {
                root->left = new Node();
            }
            root = root->left;
        }
        root->count++;
    }
}
    int countPairs(vector<int>& nums, int low, int high) {                                                   
        Node *root = new Node();
        int count = 0;
        for (int val : nums)
        {
            count += query(root, val,high + 1)-query(root,val, low);
            insert(root, val);
        }
        return count;
    }
};                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  