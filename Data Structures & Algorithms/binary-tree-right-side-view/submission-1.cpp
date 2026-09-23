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
    void RightFocusedDFS(TreeNode* node, int depth, int& maxRightDepth, vector<int>& toReturn) 
    {
        if (node == nullptr) {return;}

        depth++;

        if (depth > maxRightDepth) 
        {
            maxRightDepth = depth;
            toReturn.push_back(node->val);
        }

        RightFocusedDFS(node->right, depth, maxRightDepth, toReturn);
        RightFocusedDFS(node->left, depth, maxRightDepth, toReturn);         
    }

    vector<int> rightSideView(TreeNode* root) {
        // DFS down the tree, tracking depth and go right to left this time
        // Because we are starting right and prioritizing right, we will get to the max rightward depth first
        // From there, any rightward depth we get that is further than that, will necessarily be the new most rightward depth
        // Pass by Ref a Vector<int> so we can store the val every time we hit a new most right depth
        vector<int> toReturn;
        int depth = 0;
        int maxDepth = 0;
        if (root == nullptr) 
        {
            return toReturn;
        }
        RightFocusedDFS(root, depth, maxDepth, toReturn);
        return toReturn;
    }
};
