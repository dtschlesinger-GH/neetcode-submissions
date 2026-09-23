/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// flip val to negative to track if we visited that node before
class Solution {
public:
    unordered_map<int, Node*> nodeClones;
    void DFS(Node* root, Node* copy) 
    {
       copy->val = root->val;
       nodeClones[root->val] = copy;

       for (Node* element : root->neighbors) 
       {
            Node* toTravelTo = nullptr;
            if (nodeClones[element->val] != nullptr) 
            {
                copy->neighbors.push_back(nodeClones[element->val]);
            }
            else 
            {
                toTravelTo = new Node();
                copy->neighbors.push_back(toTravelTo);
            }
            if (toTravelTo) 
            {
                DFS(element, toTravelTo);
            }
       }
    }

    Node* cloneGraph(Node* node) {
        Node* toReturn = new Node();
        if (node == nullptr) 
        {
            return nullptr;
        }
        if (node->neighbors.empty()) 
        {
            return toReturn;
        }

        DFS(node, toReturn);
        return toReturn;
    }
};
