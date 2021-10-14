class Node
{
public:
    Node *left;  
    Node *right; 
};
class Trie
{
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(int num)
    {
        //insert bits of num in trie
        Node *temp = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;
            if (bit == 0)
            {
                if (temp->left == NULL)
                {
                    temp->left = new Node();
                }
                temp = temp->left;
            }
            else
            {
                if (temp->right == NULL)
                {
                    temp->right = new Node();
                }
                temp = temp->right;
            }
        }
    }
    //return the number present in trie which form max xor with given num.
    int max_xor_helper(int num)
    {
        int ans = 0;
        Node *temp = root;
        for (int j = 31; j >= 0; j--)
        {
            int bit = (num >> j) & 1;
            if (bit == 0)
            {
                if (temp->right != NULL)
                {
                    temp = temp->right;
                    ans += (1 << j);
                }
                else
                {
                    temp = temp->left;
                }
            }
            else
            {
                if (temp->left != NULL)
                {
                    temp = temp->left;
                    ans += (1 << j);
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
        return ans;
    }

};
class Solution {
public:
    int findMaximumXOR(vector<int>& arr) {
       Trie t;
        int n=arr.size();
       int maxXor = 0;
        for (int i = 0; i < n; i++)
        {
            int num = arr[i];
            t.insert(num);
            int curr_xor =t.max_xor_helper(num);
            maxXor = max(maxXor, curr_xor);
        }
        return maxXor;  
    }
};