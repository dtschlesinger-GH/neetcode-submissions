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
 // If this was a n-leaf tree, we could use a stack to invert, but as it is, we only need to flip the L and R
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Handle invalid cases
        if (root == nullptr || (root->left == nullptr && root->right == nullptr)) {
            return root;
        }

        InvertNode(root);
        return root;
    }

    void InvertNode(TreeNode* InNode) 
    {
        // If this was an N-Leaf tree, we would use dfs here to traverse its leaf array instead of hard calling L and R
        if (InNode->left == nullptr && InNode->right == nullptr) 
        {
            return;
        }
        if (InNode->left != nullptr) 
        {
            InvertNode(InNode->left);
        }
        if (InNode->right != nullptr) 
        {
            InvertNode(InNode->right);
        }
        TreeNode* Temp = InNode->left;
        InNode->left = InNode->right;
        InNode->right = Temp;
        return;
    }
};
