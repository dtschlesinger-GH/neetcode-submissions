class Solution {
public:
    void DFS(int currentNode, unordered_set<int>& visited, unordered_map<int, vector<int>> neighbors) 
    {
        if (visited.contains(currentNode)) 
        {
            return;
        }

        visited.insert(currentNode);

        for (const int& element : neighbors[currentNode]) 
        {
            DFS(element, visited, neighbors);
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_set<int> visited;
        unordered_map<int, vector<int>> connections;
        int numIslands = 0;

        for (vector<int>& edge : edges) 
        {
            connections[edge[0]].push_back(edge[1]);
            connections[edge[1]].push_back(edge[0]);
        }

        for (int i = 0; i < n; i++) 
        {
            if (!visited.contains(i)) 
            {
                numIslands++;
                DFS(i, visited, connections);
            }
        }
        return numIslands;
    }
};
