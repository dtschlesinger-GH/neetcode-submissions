class Solution {
public:
    bool SudokuDFS(int RowIdx, int ColIdx, 
    vector<vector<char>>& board,
    map<pair<int, int>, unordered_set<char>>& Boxes,
    vector<unordered_set<char>>& Rows, vector<unordered_set<char>>& Columns,
    map<pair<int, int>, bool>& Visited) 
    {
        if (Visited[{RowIdx, ColIdx}]) 
        {
            return true;
        }
        Visited[{RowIdx, ColIdx}] = true;


        char Val = board[RowIdx][ColIdx];
        if (Val != '.') 
        {
            if (Rows[RowIdx].find(Val) != Rows[RowIdx].end()) {
                cout << "FOUND FALSE ROW" << endl;
               return false;
            } 
            Rows[RowIdx].insert(Val);

            if (Columns[ColIdx].find(Val) != Columns[ColIdx].end()) {
                cout << "FOUND FALSE COL" << endl;
               return false;
            }          
            Columns[ColIdx].insert(Val);
            
            int row3 = (RowIdx/3);
            int col3 = (ColIdx/3);
            if (Boxes[{row3, col3}].find(Val) != Boxes[{row3, col3}].end()) {
                cout << "FOUND FALSE BOX" << endl;
                return false;
            }
            Boxes[{row3, col3}].insert(Val);
        }

        bool totalVisits = true; 
        if (RowIdx > 0) 
        {
            totalVisits &= SudokuDFS(max(RowIdx - 1, 0), ColIdx, board, Boxes, Rows, Columns, Visited);
        }
        if (RowIdx < 9) 
        {
            totalVisits &= SudokuDFS(min(RowIdx + 1, 8), ColIdx, board, Boxes, Rows, Columns, Visited);
        }
        if (ColIdx > 0) 
        {
            totalVisits &= SudokuDFS(RowIdx, max(ColIdx - 1, 0), board, Boxes, Rows, Columns, Visited);
        }
        if (ColIdx < 9) 
        {
            totalVisits &= SudokuDFS(RowIdx, min(ColIdx + 1, 8), board, Boxes, Rows, Columns, Visited);
        }
        cout << "at " << RowIdx << ", " << ColIdx << "; returning " << totalVisits << endl;
        return totalVisits;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        // What we can do here is a DFS traverse
        // use hash maps with divide positions to index what box or row or column we are looking at
        // also a hashmap for visits
        // use Pair<int, int> for location, then use those individually for column/row
        // for boxes, also use pairs, boxes will go from (0,0) to (2,2)
        vector<unordered_set<char>> Rows(9);
        vector<unordered_set<char>> Columns(9);
        map<pair<int, int>, unordered_set<char>> Boxes;
        map<pair<int, int>, bool> Visited;

        return SudokuDFS(0,0, board, Boxes, Rows, Columns, Visited);
    }
};
