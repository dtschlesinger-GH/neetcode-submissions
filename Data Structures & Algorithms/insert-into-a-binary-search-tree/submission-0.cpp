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
    TreeNode* RecursiveDFS(TreeNode* currentNode, int val) 
    {
        if (currentNode == nullptr) 
        {
            return new TreeNode(val);
        }
        if (val > currentNode->val) 
        {
            currentNode->right = RecursiveDFS(currentNode->right, val);
        }
        else 
        {
            currentNode->left = RecursiveDFS(currentNode->left, val);
        }
        return currentNode;        
    }

    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == nullptr)
        {
            root = new TreeNode(val);
            return root;
        }
        RecursiveDFS(root, val);    
        return root;
    }
};