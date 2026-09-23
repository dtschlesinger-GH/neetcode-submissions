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
    bool DFS(TreeNode* node, int minVal, int maxVal, bool isLeftSubtree, bool isRightSubtree) 
    {
        bool bIsValid = true;
        
        bIsValid &= node->val > minVal;
        bIsValid &= node->val < maxVal;
        
        if (node->left) 
        {
            bIsValid &= DFS(node->left, minVal, node->val, true, false);
            bIsValid &= node->val > node->left->val;
        }
        if (node->right) 
        {
            bIsValid &= DFS(node->right, node->val, maxVal, false, true);
            bIsValid &= node->val < node->right->val;
        }

        return bIsValid;
    }

    bool isValidBST(TreeNode* root) {
        return DFS(root, -1001, 1001, false, false);
    }
};
