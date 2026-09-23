class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> landRegionMap;
    set<pair<int, int>> visited;

    bool RegionDFS(const vector<vector<char>>& board, const int& regionID, int curRow, int curCol)
    {
        if (visited.contains({curRow, curCol})) {return false;}

        if (board[curRow][curCol] == 'X') 
        {
            return false;
        }

        landRegionMap[regionID].push_back({curRow, curCol});
        visited.insert({curRow, curCol});

        if (curRow <= 0 || curRow >= board.size() - 1 ||  curCol <= 0 || curCol >= board[0].size() - 1) 
        {
            return true;
        }

        bool bFoundEdge = false;

        bFoundEdge |= RegionDFS(board, regionID, curRow + 1, curCol);
        bFoundEdge |= RegionDFS(board, regionID, curRow - 1, curCol);
        bFoundEdge |= RegionDFS(board, regionID, curRow, curCol + 1);
        bFoundEdge |= RegionDFS(board, regionID, curRow, curCol - 1);

        return bFoundEdge;
    }
    
    void solve(vector<vector<char>>& board) {
        // skip the outside edges

        int region = -1;

        for (int i = 1; i < board.size() - 1; i++) 
        {
            for (int j = 1; j < board[0].size() - 1; j++) 
            {
                if (board[i][j] == 'O' && !visited.contains({i,j})) 
                {
                    region++;
                    if (!RegionDFS(board, region, i, j)) 
                    {
                        for (pair<int, int> element : landRegionMap[region]) 
                        {
                            board[element.first][element.second] = 'X';
                        }
                    }
                }
            }
        }
    }
};
