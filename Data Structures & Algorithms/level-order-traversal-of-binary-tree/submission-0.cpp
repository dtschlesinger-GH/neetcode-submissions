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
    vector<vector<int>> levelOrder(TreeNode* root) {
        // This is just BFS
        std::queue<TreeNode*> NodeQueue;
        vector<vector<int>> NodeList;
        NodeQueue.push(root);

        while(!NodeQueue.empty()) 
        {
            vector<int> LevelList;
            int Size = NodeQueue.size();
            for (int i = 0; i < Size; i++) 
            {
                const TreeNode* Element = NodeQueue.front();
                NodeQueue.pop();
                if (Element != nullptr) 
                {
                    LevelList.push_back(Element->val);
                    NodeQueue.push(Element->left);
                    NodeQueue.push(Element->right);
                }
            }
            if (!LevelList.empty())
            {
                NodeList.push_back(LevelList);
            }
        }
        return NodeList;
    }
};
