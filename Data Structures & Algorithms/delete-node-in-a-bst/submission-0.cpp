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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return root;

        if (key > root->val) 
        {
            root->right = deleteNode(root->right, key);
        }
        else if (key < root->val) 
        {
            root->left = deleteNode(root->left, key);
        }
        else 
        {
            if (root->left == nullptr) return root->right;
            if (root->right == nullptr) return root->left;
        

            TreeNode* curNode = root->right;
            while (curNode->left != nullptr) 
            {
                curNode = curNode->left;
            }
            curNode->left = root->left;
            TreeNode* toReturn = root->right;
            delete root;
            return toReturn;
        }
        return root;
    }
};