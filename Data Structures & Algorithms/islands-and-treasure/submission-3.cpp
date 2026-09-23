class Solution {
    // For each treasure chest in the array, DFS down lands.
    // keep a running total of how far away you are from the initial tile
    // when you get to a land tile, replae its value with Min(your distance, tile value)
    // do this for every treasure chest
    // if a tile's value is -1, return early, we can't use it to do any nav
    // to make sure we don't cycle, we need some kind of array to denote seen...
public:
    int INF = 2147483647;
    map<pair<int, int>, bool> visited;
    
    void SetChestValues(vector<vector<int>>& grid, int rowIdx, int colIdx, int distance) 
    {
        if (grid[rowIdx][colIdx] < 0) 
        {
            return;
        }

        if (visited[{rowIdx, colIdx}] && grid[rowIdx][colIdx] <= distance) 
        {
            return;
        }

        visited[{rowIdx, colIdx}] = true;
        grid[rowIdx][colIdx] = min(distance, grid[rowIdx][colIdx]);

        cout << "Visiting " << rowIdx << ", " << colIdx << endl;

        if (rowIdx > 0) 
        {
            SetChestValues(grid, rowIdx - 1, colIdx, distance + 1);
        }
        if (rowIdx < grid.size() - 1) 
        {
            SetChestValues(grid, rowIdx + 1, colIdx, distance + 1);            
        }
        if (colIdx > 0) 
        {
            SetChestValues(grid, rowIdx, colIdx - 1, distance + 1);
        }
        if (colIdx < grid[0].size() - 1) 
        {
            SetChestValues(grid, rowIdx, colIdx + 1, distance + 1);
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) 
        {
            for (int j = 0; j < grid[i].size(); j++) 
            {
                if (grid[i][j] == 0) 
                {
                    cout << "starting recursion at " << i << ", " << j << endl;
                    visited.clear();
                    SetChestValues(grid, i, j, 0);
                }
            }
        }
    }
};
