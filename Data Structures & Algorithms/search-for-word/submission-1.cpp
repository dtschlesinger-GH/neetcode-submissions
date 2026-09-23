class Solution {
public:
    bool DFSBacktrack(vector<vector<char>>& board, int rowIdx, int colIdx, string currentWord, string target, vector<vector<bool>> visited) 
    {
        currentWord += board[rowIdx][colIdx];
        visited[rowIdx][colIdx] = true;

        if (!currentWord.empty() && (currentWord.length() > target.length() || currentWord[currentWord.length() - 1] != target[currentWord.length() - 1])) 
        {
            return false;
        }

        if (currentWord == target) 
        {
            return true;
        }

        bool bFoundWord = false;
        // up
        if (rowIdx > 0) 
        {
            if (!visited[rowIdx - 1][colIdx]) 
                bFoundWord |= DFSBacktrack(board, rowIdx - 1, colIdx, currentWord, target, visited);
        }

        // down
        if (rowIdx < board.size() - 1) 
        {
            if (!visited[rowIdx + 1][colIdx]) 
                bFoundWord |= DFSBacktrack(board, rowIdx + 1, colIdx, currentWord, target, visited);
        }

        // left
        if (colIdx > 0) 
        {
            if (!visited[rowIdx][colIdx - 1]) 
                bFoundWord |= DFSBacktrack(board, rowIdx, colIdx - 1, currentWord, target, visited);
        }

        // right
        if (colIdx < board[0].size() - 1) 
        {
            if (!visited[rowIdx][colIdx + 1]) 
                bFoundWord |= DFSBacktrack(board, rowIdx, colIdx + 1, currentWord, target, visited);
        }

        return bFoundWord;
    }

    bool exist(vector<vector<char>>& board, string word) {
        // string has to be in order
        // failure conditions then are when a letter does not match, or when the word we are building exceeds word length
        // At each cell, we can either include, or exclude the letter
        // then we recurse UDLR
        // if we hit the word, return true.  If we hit a bad condition, return false;
        // each path would need its own index hash to not end up in a loop

        // the alternative is to start by iterating through, then if the letter matches the ith letter of the word, start a DFS
        // this still needs a index hash to make sure we don't loop
        bool bFoundResult;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) 
        {
            for (int j = 0; j < board[i].size(); j++) 
            {
                if (word[0] == board[i][j]) 
                {
                    bFoundResult |= DFSBacktrack(board, i, j, "", word, visited);
                    if (bFoundResult) 
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
