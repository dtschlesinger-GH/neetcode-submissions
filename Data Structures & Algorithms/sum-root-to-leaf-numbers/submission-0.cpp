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
    void DFS(TreeNode* node, int partialPath, vector<int>& fullPaths) 
    {
        if (node == nullptr) 
        {
            return;
        }

        partialPath = partialPath * 10 + node->val;

        if (node->left == nullptr && node->right == nullptr) 
        {
            cout << "partial path is " << partialPath << endl;
            fullPaths.push_back(partialPath);
            return;
        }

        DFS(node->left, partialPath, fullPaths);
        DFS(node->right, partialPath, fullPaths);
    }

    int sumNumbers(TreeNode* root) {
        vector<int> fullPaths;
        int path = 0;
        DFS(root, path, fullPaths);
        
        int totalSum = 0;
        for (const int path : fullPaths) 
        {
            totalSum += path;
        }
        return totalSum;
    }
};