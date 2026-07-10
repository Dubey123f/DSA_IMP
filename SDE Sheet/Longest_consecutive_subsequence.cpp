class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0){
            return 0;
        }
        sort(nums.begin(),nums.end());
        int c=0;
        int maxL=0;
     for(int i=1;i<n;i++){
        if(nums[i]-nums[i-1]==1){
            c++;
            maxL=max(maxL,c);
        }
        else if(nums[i]==nums[i-1]){
            continue;
        }
        else{
            c=0;
        }
     }
     return maxL+1;
    }
};