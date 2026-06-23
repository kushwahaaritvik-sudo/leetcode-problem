class Solution {
public:
    bool searchInRow(vector<vector<int>> mat, int target, int row) {
        int n = mat[0].size();
        int start = 0;
        int end = n - 1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (target == mat[row][mid]) {
                return true;
            }
            else if (target > mat[row][mid]) {  // Bug fix: compare with mat[row][mid], not mid
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        return false;  // Bug fix: missing return statement
    }
    
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int m = mat.size();
        int n = mat[0].size();
        
        int startrow = 0;
        int endrow = m - 1;
        
        while (startrow <= endrow) {
            int mid = startrow + (endrow - startrow) / 2;
            
            if (target >= mat[mid][0] && target <= mat[mid][n - 1]) {
                return searchInRow(mat, target, mid);  // Bug fix: add return statement
            }
            else if (target > mat[mid][n - 1]) {  // Bug fix: use > instead of >=
                startrow = mid + 1;
            }
            else {
                endrow = mid - 1;
            }
        }
        return false;  // Bug fix: missing return statement
    }
};