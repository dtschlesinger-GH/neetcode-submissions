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
    int DFS(TreeNode* Node, int& Depth) 
    {
        if (Node == nullptr) {
            return 0;
        }
        int left = DFS(Node->left, Depth);
        int right = DFS(Node->right, Depth);
        Depth = std::max(Depth, left + right);
        return 1 + std::max(left, right);
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int Depth = 0;
        DFS(root, Depth);
        return Depth;
    }
};
