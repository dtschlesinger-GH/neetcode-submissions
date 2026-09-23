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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> PQueue;
        queue<TreeNode*> QQueue;

        PQueue.push(p);
        QQueue.push(q);

        while (!PQueue.empty() && !QQueue.empty()) 
        {
            // if you have a null mismatch, that's a node mismatch, and you sfront
            if ((PQueue.front() == nullptr && QQueue.front() != nullptr)
                || (PQueue.front() != nullptr && QQueue.front() == nullptr) ) 
                {
                    return false;
                }

            // If we are looking at a null node, then just pop it, and continue
            if (PQueue.front() == nullptr && QQueue.front() == nullptr) 
            {
                PQueue.pop();
                QQueue.pop();
                continue;
            }

            // If what value is on front does not match, we need to return false
            if (PQueue.front()->val != QQueue.front()->val) 
            {
                return false;
            }

            // We have matching vals here, so take each child and add it to the queue to explore
            TreeNode* PTop = PQueue.front();
            PQueue.pop();
            TreeNode* QTop = QQueue.front();
            QQueue.pop();
            PQueue.push(PTop->left);
            PQueue.push(PTop->right);
            QQueue.push(QTop->left);
            QQueue.push(QTop->right);
        }
        return true;
    }
};
