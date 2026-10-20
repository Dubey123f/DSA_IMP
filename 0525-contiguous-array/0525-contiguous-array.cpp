class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int c=0;
        vector<int>p(n);
        map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                nums[i]=-1;
            }
            else{
                nums[i]=1;
            }
        }
        for(int i=0;i<n;i++){
            if(i==0){
                p[i]=nums[i];
            }
            else{
                p[i]=p[i-1]+nums[i];
            }
            if(mp.find(p[i])!=mp.end()){
                c=max(c,i-mp[p[i]]);
            }
            else{
                mp[p[i]]=i;
            }

        }
        return c;
    }
}; 