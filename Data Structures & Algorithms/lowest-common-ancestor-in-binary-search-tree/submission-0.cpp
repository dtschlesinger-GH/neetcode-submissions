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
    void DFS(TreeNode* node, int pVal, int qVal, TreeNode* ToReturn) 
    {
        if (node == nullptr) return;
        if (node->val == pVal || node->val == qVal) 
        {
            cout << "setting toReturn to" << node->val << "from val match" << endl;
            ToReturn->val = node->val;
            return;
        }
        if (pVal < node->val && qVal < node->val) 
        {
            DFS(node->left, pVal, qVal, ToReturn);
        }
        else if (pVal > node->val && qVal > node->val) 
        {
            DFS(node->right, pVal, qVal, ToReturn);
        }
        else
        {
            cout << "setting toReturn to" << node->val << "from Split" << endl;
            ToReturn->val = node->val;
        }
        return;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Use DFS to find the two nodes by using L/R next traversal based on greater or lower.
        // If you hit a value that is between the two, by definition that is the lowest that it can go, so return that
        // Otherwise, if you hit one of the two values, that's the lowest it can go, so return that.
        TreeNode* ToReturn = root;
        DFS(root, p->val, q->val, ToReturn);
        return ToReturn;
    }
};
