class Solution {
public:
    int combination(int n , int r ){
        if(r>n-r){
            r=n-r;
        }

        long long result = 1;

         for(int i = 1 ; i <= r;i ++){
            result = (result * (n-i+1))/i;
            
         }

         return result;

    }
    int uniquePaths(int m, int n) {
        
        return combination((m+n)-2,m-1);
    }
};