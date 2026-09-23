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
    // Do DFS
    // Keep int counter of max you have enountered on this recursion
    // If next val is larger, increment passed in global counter
    // If next is smaller, continue

    // return the int counter

    void DFSGoodNodes(TreeNode* node, int recursiveMax, int& goodNodesCounter) 
    {
        if (node == nullptr) return;

        if (node->val >= recursiveMax) 
        {
            recursiveMax = node->val;
            goodNodesCounter++;
        }

        DFSGoodNodes(node->left, recursiveMax, goodNodesCounter);
        DFSGoodNodes(node->right, recursiveMax, goodNodesCounter);
    }

    int goodNodes(TreeNode* root) {
        int numGoodNodes = 0;
        if (root != nullptr) {
            DFSGoodNodes(root, root->val, numGoodNodes);
        }
        return numGoodNodes;
    }
};
