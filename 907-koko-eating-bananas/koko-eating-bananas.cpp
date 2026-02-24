class Solution {
public:

    bool canEatAll(vector<int>& piles, int mid, int h){
        int actualHours = 0;
        for(int &x : piles){ // kitne banana hai har ek piles ma wo is x ma aa rhe hain
            actualHours += x/mid;

            if(x%mid != 0){
                actualHours++;
            }
        }
        return actualHours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(begin(piles), end(piles));

        while(l<r){
            int mid = l + (r-l)/2; // per hour she can eat mid number of bananas

            if(canEatAll(piles,mid,h)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};