class Solution {
public:
    int maxArea = 0;

    int DFS(vector<vector<int>>& grid, int rowIdx, int colIdx, int rollingArea) 
    {
        if (grid[rowIdx][colIdx] == 0) 
        {
            return rollingArea;
        }

        grid[rowIdx][colIdx] = 0;
        rollingArea++;
        maxArea = max(maxArea, rollingArea);

        if (rowIdx > 0) 
        {
            rollingArea = DFS(grid, rowIdx - 1, colIdx, rollingArea);
        }
        if (rowIdx < grid.size() - 1) 
        {
            rollingArea = DFS(grid, rowIdx + 1, colIdx, rollingArea);
        }
        if (colIdx > 0) 
        {
            rollingArea = DFS(grid, rowIdx, colIdx - 1, rollingArea);
        }
        if (colIdx < grid[0].size() - 1) 
        {
            rollingArea = DFS(grid, rowIdx, colIdx + 1, rollingArea);
        }
        return rollingArea;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) 
        {
            for (int j = 0; j < grid[0].size(); j++) 
            {
                if (grid[i][j] == 1) 
                {
                    DFS(grid, i, j, 0);
                }
            }
        }
        return maxArea;
    }
};
