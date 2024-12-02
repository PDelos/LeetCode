class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int colL = 0, colR = matrix[0].size()-1;
        int rowL = 0, rowR = matrix.size()-1;
        int m;


        // Do a binary search on the rows to see in what row it should be located

        while(rowL <= rowR){
            m = rowL+(rowR-rowL)/2;
            if(matrix[m][0] == target) return true;

            if(matrix[m][0] < target) rowL = m+1;
            else rowR = m-1;
        }
        if (rowR == -1) return false;

        while(colL <= colR){
            m = colL+(colR-colL)/2;
            if(matrix[rowR][m] == target) return true;

            if(matrix[rowR][m] < target) colL = m+1;
            else colR = m-1;
        }

        return false;
    }
};
