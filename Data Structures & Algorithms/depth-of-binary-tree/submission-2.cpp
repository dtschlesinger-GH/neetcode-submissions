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
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;

        int Depth = 0;
        int MaxDepth = 0;
        Traverse(root, Depth, MaxDepth);
        return MaxDepth;
    }

    void Traverse(TreeNode* InNode, int Depth, int& MaxDepth) {
        Depth++;
        if (Depth > MaxDepth) {
            MaxDepth = Depth;
        }
        if (InNode->left != nullptr) {
            Traverse(InNode->left, Depth, MaxDepth);
        }
        if (InNode->right != nullptr) {
            Traverse(InNode->right, Depth, MaxDepth);
        }
    }
};
