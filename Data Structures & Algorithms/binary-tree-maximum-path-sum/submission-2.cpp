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
    int pathMax = numeric_limits<int>::lowest();

    int DFS(TreeNode* node) 
    {
        // start by going down the tree.
        // when you are nullptr, that's your end condition
        if (node == nullptr) 
        {
            // if we get an all negative tree, and we are returning 0 here, does that break things?
            return 0;
        }

        // get the sum of your children, whatever that might be
        // take the max value between your own value, and the sum of your children + your value
        // this simulates abandoning the path if it would be more profitable to end your path with you
        int leftVal = DFS(node->left);
        int rightVal = DFS(node->right);
        
        // If we choose the center path, our backtrack stops there, we can't do any more
        // So we need to check center against max, but then we need to return only max between left and right
        int centerVal = node->val + leftVal + rightVal;

        int largestPathVal = max({node->val, node->val + leftVal, node->val + rightVal});

        // if that value is larger than our max, set max to that
        if (pathMax < largestPathVal) 
        {
            pathMax = largestPathVal;
        }
        if (pathMax < centerVal) 
        {
            pathMax = centerVal;
        }

        // return your value
        return largestPathVal;

    }

    int maxPathSum(TreeNode* root) {
        DFS(root);
        return pathMax;
    }
};
