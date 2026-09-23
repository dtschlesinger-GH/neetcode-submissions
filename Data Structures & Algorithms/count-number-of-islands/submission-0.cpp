class Solution {
public:
    void DFS(vector<vector<char>>& grid, int rowIdx, int colIdx) 
    {
        if (grid[rowIdx][colIdx] == '0' || grid[rowIdx][colIdx] == '#') 
        {
            return;
        }

        grid[rowIdx][colIdx] = '#';

        if (rowIdx > 0) 
        {
            DFS(grid, rowIdx - 1, colIdx);
        }
        if (rowIdx < grid.size() - 1) 
        {
            DFS(grid, rowIdx + 1, colIdx);
        }
        if (colIdx > 0) 
        {
            DFS(grid, rowIdx, colIdx - 1);
        }
        if (colIdx < grid[0].size() - 1) 
        {
            DFS(grid, rowIdx, colIdx + 1);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // DFS, start in the upper right
        // if its a 0, mark visited and move on.
        // if its a 1, we need to find all other connected landmass, and increment land counter by 1
        // when we find a landmass, do we need to do special handling to mark out the whole of that landmass?
            // if we did, what would that special handling even look like?
                // flip some kind of mode bool gate, look only for land, and then mark that land visited
                // this incurrs a LOT of repeated work, looking at water that we aren't going to be marking though?
                // We can mark the water, but we can't DFS into it, at least not when we are in seeking mode
            // if we decided to do this, what happens in a case like example 2, when we immediately mark all our neighbors and ourselves visited?
                // those cases would break us, DFS only works because its non-interrupted, we need to to be semi-continuous

        // I don't think special handling works, or is a great idea here
        // if we don't do special handling, what can we say?  If a neighbor has been visited that is land, its still the same one?

        // What about if we just iterate across columns and rows, and then only when we hit a 1, we DFS that, and mark them visited?
        // sure, that shoud probably work, but I'm worried its too slow

        int numIslands = 0;

        for (int i = 0; i < grid.size(); i++) 
        {
            for (int j = 0; j < grid[i].size(); j++) 
            {
                if (grid[i][j] == '1') 
                {
                    numIslands++;
                    DFS(grid, i, j);
                }
            }
        }
        return numIslands;
    }
};
