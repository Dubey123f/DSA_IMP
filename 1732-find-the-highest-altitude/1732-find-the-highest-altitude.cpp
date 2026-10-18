class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n=gain.size();
        vector<int>ps(n+1);
        ps[0]=0;
        for(int i=1;i<=n;i++){
            ps[i]=ps[i-1]+gain[i-1];
        }
        int maxi=*max_element(ps.begin(),ps.end());
        return maxi;
    }
};