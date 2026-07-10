#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the number of intervals: ";
    cin>>n>>m;
    vector<vector<int>>intervals(n,vector<int>(2));
    cout<<"Enter the intervals (start end): ";
    for(int i=0;i<n;i++){
        cin>>intervals[i][0]>>intervals[i][1];
    }
    sort(intervals.begin(),intervals.end());
    cout<<"The Intervals are: "<<endl;
    for(int i=0;i<n;i++){
        cout<<"["<<intervals[i][0]<<", "<<intervals[i][1]<<"] ";
    }
    int startindex=intervals[0][0];
    int endindex=intervals[0][1];
    cout<<"The startindex is: "<<startindex<<endl;
    cout<<"The endindex is: "<<endindex<<endl;
    vector<vector<int>>merged;
    for(int i=1;i<n;i++){
        if(intervals[i][0]<=endindex){
            endindex=max(endindex,intervals[i][1]);
            startindex=min(startindex,intervals[i][0]);
        }
        else{
            merged.push_back({startindex,endindex});
            startindex=intervals[i][0];
            endindex=intervals[i][1];
        }

    }
    merged.push_back({startindex,endindex});
    cout<<"The Merged Intervals are: "<<endl;
    for(int i=0;i<merged.size();i++){
        cout<<"["<<merged[i][0]<<", "<<merged[i][1]<<"] ";
    }


}