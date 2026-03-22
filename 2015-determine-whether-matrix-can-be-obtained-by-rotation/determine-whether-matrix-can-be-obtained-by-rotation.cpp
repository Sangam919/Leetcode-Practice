class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        bool breakOut = false;

        // Check Top Version
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] != target[i][j]){
                    breakOut = true;
                    break;
                }
            }
            if(breakOut) break;
        }
        if(!breakOut){
            return true;
        }
        breakOut = false;

        // Checking Right Version
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] != target[j][n-i-1]){
                    breakOut = true;
                    break;
                }
            }
            if(breakOut) break;
        }
        if(!breakOut){
            return true;
        }
        breakOut = false;

        // Checking Bottom Version
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] != target[n-i-1][n-j-1]){
                    breakOut = true;
                    break;
                }
            }
            if(breakOut) break;
        }
        if(!breakOut){
            return true;
        }
        breakOut = false;

        // Checking Left Version
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] != target[n-j-1][i]){
                    breakOut = true;
                    break;
                }
            }
            if(breakOut) break;
        }
        if(!breakOut){
            return true;
        }
        
        return false;
    }
};