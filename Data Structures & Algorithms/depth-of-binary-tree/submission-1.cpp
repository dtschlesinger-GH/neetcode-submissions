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

        int Depth = 1;
        int MaxDepth = 0;
        DFS(root, Depth, MaxDepth);
        return MaxDepth;
    }

    void DFS(TreeNode* node, int Depth, int& MaxDepth) 
    {
        if (node == nullptr) {return;}

        if (!node->left && !node->right) 
        {
            if (Depth > MaxDepth) 
            {
                MaxDepth = Depth;
            }
        }
        DFS(node->left, Depth + 1, MaxDepth);
        DFS(node->right, Depth + 1, MaxDepth);
    }    
};
