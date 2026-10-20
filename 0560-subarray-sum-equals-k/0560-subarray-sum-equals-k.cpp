class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
    vector<int>p(n);
    map<int,int>mp;
    int c=0;
    mp[0]=1;
    for(int i=0;i<n;i++){
        if(i==0){
            p[i]=nums[i];
        }
        else{
            p[i]=p[i-1]+nums[i];
        }
        c+=mp[p[i]-k];
        mp[p[i]]++;
    }
    return c;
    }
};