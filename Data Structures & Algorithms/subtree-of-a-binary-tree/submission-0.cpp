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
    bool CheckForSubtree(TreeNode* original, TreeNode* subroot) 
    {
        if (original == nullptr && subroot == nullptr) 
        {
            return true;
        }
        if (original == nullptr || subroot == nullptr) 
        {
            return false;
        }
        if (original->val != subroot->val) 
        {
            return false;
        }
        return (CheckForSubtree(original->left, subroot->left) 
                && CheckForSubtree(original->right, subroot->right));

    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr) 
        {
            return false;
        }
        // Get to the first node that shares a value with the subroot's root head
        if (root->val == subRoot->val) 
        {
            // once we do, we want to run a mini dfs or BFS, to check if they match.
            if (CheckForSubtree(root, subRoot)) 
            {
                return true;
            }
        }
        // if they do, return true, but otherwise we keep going, because there could be multiple nodes with that value.
        return (isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot));
    }
};
