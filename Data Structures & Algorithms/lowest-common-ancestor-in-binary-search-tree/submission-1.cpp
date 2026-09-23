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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // If both p and q are less than root, recurse left only
        // If both p and q are greater than root, recurse right only
        // if p and q are on opposite sides of root, recurse both)

        if (root == nullptr) 
        {
            return nullptr;
        }
        if (root->val == p->val || root->val == q->val) 
        {
            // I don't think this is right?
            return root;
        }

        if (root->val > p->val && root->val > q->val) 
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else if (root->val < p->val && root->val < q->val) 
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else 
        {
            TreeNode* Left = lowestCommonAncestor(root->left, p, q);
            TreeNode* Right = lowestCommonAncestor(root->right, p, q);
            if (Left && Right) {
                return root;
            }
            if (!Left && !Right) {
                return nullptr;
            }
            if (Left && !Right) {
                return Left;
            }
            if (!Left && Right) {
                return Right;
            }
        }
    }
};
