//prob link: https://leetcode.com/problems/unique-paths-ii/

class Solution {
public:
    //this is going to be a recursive function
    /*int findPaths(vector<vector<int>> obstacleGrid, int&paths, int currentRow, int currentCol) {
        // base case
       if(currentRow == obstacleGrid.size()-1 && currentCol == obstacleGrid[0].size()) {
            return paths + 1 ;
        }
        
        //recursive case 
        bool isThereAnyWhereLedtToMove = false;
        //check if we can go down
        if(obstacleGrid[currentRow+1][currentCol] == 0 && (currentRow+1) < obstacleGrid.size() && currentCol < obstacleGrid[0].size()) {
            isThereAnyWhereLedtToMove = true ;
            paths += findPaths(obstacleGrid, paths, currentRow+1, currentCol) ;
        }
        
        //checking if we can take right
        if(obstacleGrid[currentRow][currentCol+1] == 0 && (currentRow) < obstacleGrid.size() && (currentCol+1) < obstacleGrid[0].size()) {
            isThereAnyWhereLedtToMove = true ;
            paths += findPaths(obstacleGrid, paths, currentRow, currentCol+1) ;
        }
        
        return paths ;
    }*/
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        /*int paths = 0 ;
        return findPaths(obstacleGrid, paths, 0, 0) ;*/
        int R = obstacleGrid.size();
        int C = obstacleGrid[0].size();

        // If the starting cell has an obstacle, then simply return as there would be
        // no paths to the destination.
        if(obstacleGrid[0][0] == 1) {
            return 0;
        }

        // Number of ways of reaching the starting cell = 1.
        obstacleGrid[0][0] = 1;

        // Filling the values for the first column
        for (int i = 1; i < R; i++) {
            obstacleGrid[i][0] = (obstacleGrid[i][0] == 0 && obstacleGrid[i - 1][0] == 1) ? 1 : 0;
        }

        // Filling the values for the first row
        for (int i = 1; i < C; i++) {
            obstacleGrid[0][i] = (obstacleGrid[0][i] == 0 && obstacleGrid[0][i - 1] == 1) ? 1 : 0;
        }

        // Starting from cell(1,1) fill up the values
        // No. of ways of reaching cell[i][j] = cell[i - 1][j] + cell[i][j - 1]
        // i.e. From above and left.
        for (int i = 1; i < R; i++) {
            for (int j = 1; j < C; j++) {
                if (obstacleGrid[i][j] == 0) {
                    obstacleGrid[i][j] = obstacleGrid[i - 1][j] + obstacleGrid[i][j - 1];
                } else {
                    obstacleGrid[i][j] = 0;
                }
            }
        }

        // Return value stored in rightmost bottommost cell. That is the destination.
        return obstacleGrid[R - 1][C - 1];
    } 
};
