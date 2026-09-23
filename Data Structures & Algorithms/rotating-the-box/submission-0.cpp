class Solution {
public:
    

    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        // column becomes row
        // Row from 0-n flips, becomes column from n-0

        vector<vector<char>> rotatedBox(boxGrid[0].size(), vector<char>(boxGrid.size(), '.'));
        
        // do this as a two pointer approach, in a single pass
        for (int row = 0; row < boxGrid.size(); row++) 
        {
            int stonePlacementIndex = boxGrid[row].size() - 1;
            for (int col = boxGrid[row].size() - 1; col >= 0; col--) 
            {
                if (boxGrid[row][col] == '#') 
                {
                    rotatedBox[stonePlacementIndex][boxGrid.size() - row - 1] = '#';
                    stonePlacementIndex--;
                }
                if (boxGrid[row][col] == '*') 
                {
                    rotatedBox[col][boxGrid.size() - row - 1] = '*';
                    stonePlacementIndex = col - 1;
                }
            }
        }

        return rotatedBox;
    }
};