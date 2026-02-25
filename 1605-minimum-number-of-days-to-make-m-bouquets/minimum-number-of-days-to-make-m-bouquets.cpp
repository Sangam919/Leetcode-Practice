class Solution {
public:
int check(int m,int n,vector<int>bloomday ,int k ,int mid){
     int count=0;
            for(int i=0;i<n;i++){
                if(bloomday[i]<=mid){
                    count++;
                    if(count==(k)){
                        m=m-1;
                        if(m==0) return 0;
                        count=0;
                    }
                }else{
                    count=0;
                }
            }
            return m;// 0 it mean it can be an answer;
}
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if( ( n/m) < k ) return -1;
        int low = 1;
        long long high = *max_element(bloomDay.begin(), bloomDay.end() );
        int result =-1;
        while(low<=high){
            int mid = low+(high-low)/2;
            int ans  = check(m,n,bloomDay,k,mid);
           if(ans==0){
            high=mid-1;
            result = mid;
           }else{
            low=  mid+1;
           }

        }
        return result;
    }
};
