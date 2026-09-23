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
    int DFS(TreeNode* node, bool& balanced) 
    {
       if (node == nullptr) {return 0;}

       int leftDepth = DFS(node->left, balanced);
       int rightDepth = DFS(node->right, balanced);

        balanced &= abs(leftDepth - rightDepth) <= 1;

        return 1 + max(leftDepth, rightDepth);
    }

    bool isBalanced(TreeNode* root) 
    {
        int leftDepth = 0;
        int rightDepth = 0;
        bool balanced = true;

        DFS(root, balanced);   

        return balanced;
    }
};
