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
    void RightFocusedDFS(TreeNode* Node, const int CurrentDepth, int& MaxRightDepth, vector<int>& ToReturn) 
    {
        if (Node == nullptr) return;
        if (CurrentDepth > MaxRightDepth) 
        {
            MaxRightDepth = CurrentDepth;
            ToReturn.push_back(Node->val);
        }

        RightFocusedDFS(Node->right, CurrentDepth + 1, MaxRightDepth, ToReturn);
        RightFocusedDFS(Node->left, CurrentDepth + 1, MaxRightDepth, ToReturn);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> ToReturn;
        if (root == nullptr) return ToReturn;
        int MaxRightDepth = 0;
        RightFocusedDFS(root, 1, MaxRightDepth, ToReturn);
        return ToReturn;
    }
};
