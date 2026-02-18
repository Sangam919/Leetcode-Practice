class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last =-1;
        while(n>0){
            if(n%2 == 0){
                if(last == 0){
                    return false;
                }
                last = 0;
            }
            else{
                if(last == 1){
                    return false;
                }
                last = 1;
            }

            n = n/2;
        }
        return true;
    }
};