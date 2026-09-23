class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        //vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        vector<pair<int, int>> directions = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        queue<pair<int, int>> BFS;
        pair<int, int> startingPos = {0,0};
        pair<int, int> endingPos = {grid.size() - 1, grid[grid.size() - 1].size() - 1};
        int distance = 0;
        bool foundEnd = false;

        if (grid[startingPos.first][startingPos.second] == 1 || grid[endingPos.first][endingPos.second] == 1) 
        {
            return -1;
        }
        BFS.push(startingPos);

        while (!BFS.empty()) 
        {
            distance++;
            int BFSIterationSize = BFS.size();
            for (int i = 0; i < BFSIterationSize; i++) 
            {
                const pair<int, int> top = BFS.front();
                BFS.pop();
                grid[top.first][top.second] = 1;
                if (top == endingPos) 
                {
                    return distance;
                }

                // we can either do additional pop/push actions, but simplify just push all neighbors and check here,
                // or we can do determination here, and then avoid additional push/pops
                for (const pair<int, int>& element : directions) 
                {
                    const pair<int, int> neighbor = {top.first + element.first, top.second + element.second};
                    if (neighbor.first >= 0 && neighbor.second >= 0 && neighbor.first < grid.size() && neighbor.second < grid[0].size() 
                        && grid[neighbor.first][neighbor.second] == 0) 
                    {
                        BFS.push(neighbor);
                        grid[neighbor.first][neighbor.second] = 1;
                    }
                }
            }
        }
        return -1;
    }
};