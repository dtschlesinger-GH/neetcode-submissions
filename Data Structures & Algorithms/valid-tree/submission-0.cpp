class Solution {
public:

    bool validTree(int n, vector<vector<int>>& edges) {
        //must have: no cycles, all nodes are connected as one component, any two nodes have only one path
        unordered_map<int, vector<int>> neighbors;
        unordered_set<int> visited;
        queue<pair<int, int>> bfsQueue;
        for ( vector<int>& pairings : edges) 
        {
            neighbors[pairings[0]].push_back(pairings[1]);
            neighbors[pairings[1]].push_back(pairings[0]);
        }

        bfsQueue.push({0, -1});
        visited.insert(0);

        while (!bfsQueue.empty()) 
        {
            pair<int, int> currentNode = bfsQueue.front();
            bfsQueue.pop();
            for (int neighbor : neighbors[currentNode.first]) 
            {
                if (neighbor == currentNode.second) 
                {
                    continue;
                }
                if (visited.contains(neighbor)) 
                {
                    return false;
                }
                visited.insert(neighbor);
                bfsQueue.push({neighbor, currentNode.first});
            }
        }

        return visited.size() == n;
    }
};
