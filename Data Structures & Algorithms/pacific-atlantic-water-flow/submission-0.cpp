class Solution {
public:
    set<pair<int, int>> pacificVisited;
    set<pair<int, int>> atlanticVisited;
    vector<vector<int>> toReturn;
    
    void DFS(const vector<vector<int>>& heights, int row, int col, bool bIsPacific) 
    {
        if ((bIsPacific && pacificVisited.contains({row, col})) || (!bIsPacific && atlanticVisited.contains({row, col}))) 
        {
            return;
        }

        if (bIsPacific) 
        {
            pacificVisited.insert({row, col});
        }
        else 
        {
            atlanticVisited.insert({row, col});
            if (pacificVisited.contains({row, col})) 
            {
                vector<int> coord = {row, col};
                toReturn.push_back(coord);
            }
        }

        int up = row - 1;
        int down = row + 1;
        int left = col - 1;
        int right = col + 1;

        if (up >= 0 && heights[up][col] >= heights[row][col]) 
        {
            DFS(heights, up, col, bIsPacific);
        }
        if (down < heights.size() && heights[down][col] >= heights[row][col]) 
        {
            DFS(heights, down, col, bIsPacific);
        }
        if (left >= 0 && heights[row][left] >= heights[row][col]) 
        {
            DFS(heights, row, left, bIsPacific);
        }
        if (right < heights[0].size() && heights[row][right] >= heights[row][col]) 
        {
            DFS(heights, row, right, bIsPacific);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // row 0, col 0 all have pacific
        // row n-1, col n-1, all have atlantic
        // go from the edges, flow upward to minimize calls
        // backpropagating a tile that reached pacific and atlantic is a giant pain
        // so instead we just do two DFS

        // Do we need to track what we already visited?
            // We do, we need a differnt one for pacific and atlantic
        vector<pair<int, int>> toVisit;
        for (int i = 0; i < heights.size(); i++) 
        {
            toVisit.push_back({i, 0});
        }
        for (int j = 0; j < heights[0].size(); j++) 
        {
            toVisit.push_back({0, j});
        }
        for (const pair<int, int>& element : toVisit) 
        {
            DFS(heights, element.first, element.second, true);
        }
        
        toVisit.clear();

        for (int i = 0; i < heights.size(); i++) 
        {
            toVisit.push_back({i, heights[0].size() - 1});
        }
        for (int j = 0; j < heights[0].size(); j++) 
        {
            toVisit.push_back({heights.size() - 1, j});
        }
        for (const pair<int, int>& element : toVisit) 
        {
            DFS(heights, element.first, element.second, false);
        }
        return toReturn;
    }
};
