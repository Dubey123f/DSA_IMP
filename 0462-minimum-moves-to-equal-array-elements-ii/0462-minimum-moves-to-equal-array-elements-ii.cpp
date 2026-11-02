class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int median=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        if(n%2==0){
            median=(nums[n/2]+nums[n/2-1])/2;
        }
        else{
            median=nums[n/2];
        }
        long long moves=0;
        for(int i=0;i<n;i++){
            moves+=abs(nums[i]-median);
        }
        return moves;
    }
};