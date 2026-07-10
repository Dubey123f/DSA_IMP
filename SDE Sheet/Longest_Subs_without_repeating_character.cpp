class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int l=0;
    int n=s.size();
int maxl=0;
vector<bool>vis(256,false);
if(n==0 || n==1){
    return n;
}
int r=0;
while(r<n){
   while(vis[s[r]]){
        vis[s[l]]=false;
        l++;
    }
    vis[s[r]]=true;
    maxl=max(maxl,r-l+1);
    r++;
}
return maxl;
   
    }
};