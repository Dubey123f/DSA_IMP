class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ts=0,n=nums.size();
        vector<int>pl(n);
        pl[0]=nums[0];
        for(int i=1;i<n;i++){
          pl[i]=pl[i-1]+nums[i];
        }
        for(int i=0;i<n;i++){
            ts+=nums[i];
        }
        for(int i=0;i<n;i++){

            int ls,rs;
            if(i==0){
                ls=0;
            }
            else{
                ls=pl[i-1];
            }
            rs=ts-ls-nums[i];
            if(ls==rs){
                return i;
            }
        }
        return -1;
    }
};