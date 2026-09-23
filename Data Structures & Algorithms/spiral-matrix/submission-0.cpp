class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0;
        int top = 0;
        int bottom = matrix.size() - 1;
        int right = matrix[0].size() - 1;
        int totalCount = matrix.size() * matrix[0].size();
        vector<int> toReturn;

        while (left <= right && top <= bottom) 
        {
            for (int rowTraverse = left; rowTraverse <= right; rowTraverse++) 
            {
                toReturn.push_back(matrix[top][rowTraverse]);
                totalCount--;
            }
            if (totalCount == 0) {break;}
            top++;

            for (int colTraverse = top; colTraverse <= bottom; colTraverse++) 
            {
                toReturn.push_back(matrix[colTraverse][right]);
                totalCount--;
            }
            if (totalCount == 0) {break;}
            right--;

            for (int rowTraverse = right; rowTraverse >= left; rowTraverse--) 
            {
                toReturn.push_back(matrix[bottom][rowTraverse]);
                totalCount--;
            }
            if (totalCount == 0) {break;}
            bottom--;

            for (int colTraverse = bottom; colTraverse >= top; colTraverse--) 
            {
                toReturn.push_back(matrix[colTraverse][left]);
                totalCount--;
            }
            if (totalCount == 0) {break;}
            left++;
        }
        return toReturn;
    }
};
