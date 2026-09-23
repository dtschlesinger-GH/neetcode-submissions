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
     int Index = 0;
    unordered_map<int, int> inOrderIndex;
    TreeNode* TraverseTree(const vector<int>& preorder, int start, int end) 
    {
        if (start > end) {
            return nullptr;
        }

        TreeNode* toReturn = new TreeNode();
        toReturn->val = preorder[Index++];
        int midPoint = inOrderIndex[toReturn->val];

        // subdivide your subtree into left of you and right of you, then pass that through recursively
        toReturn->left = TraverseTree(preorder, start, midPoint - 1);
        toReturn->right = TraverseTree(preorder, midPoint + 1, end);

        return toReturn;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // preorder does not include nulls, so that's what the inorder is going to fix for
        // inorder is left root right, so we can get what is a root from there, telling us which have null and which don't
        // Start at the first root entry in pre-order, we can be garunteed this is a root.
        // Find the root in the inorder traversal, whatever is to its left and right are garunteed to be its left and right nodes
        // Split into two subarrays in the InOrder, left of the root and right of the root, these are the children
        // If you have a node one over from your starting position of L or R, then that is another root node, split into subtrees again
        // If you don't, you are the last child on that side, so you are done 
        for (int i = 0; i < inorder.size(); i++) 
        {
            inOrderIndex[inorder[i]] = i;
        }
        return TraverseTree(preorder, 0, inorder.size() - 1);

    }
};
