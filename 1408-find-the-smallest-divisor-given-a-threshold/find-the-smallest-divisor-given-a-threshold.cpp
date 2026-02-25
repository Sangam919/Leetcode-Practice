class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int l=1;
        int ans=0;
        int r=nums[n-1];
        while(l<=r){
            int mid=l+(r-l)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                if(nums[i]%mid!=0){
                    sum+=1;
                }
                sum+=(nums[i]/mid);
            }
            if(sum<=threshold){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};