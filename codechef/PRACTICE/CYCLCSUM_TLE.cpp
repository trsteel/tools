#include <iostream>
#include <vector>
#include <math.h>
#include <stdio.h>

using namespace std;

int process(vector<int>& vec) {
    int res = vec[1], mi = vec[0];
    for(int i=1;i<vec.size();i++) {
        res = max(res, vec[i]-mi);
        mi = min(mi, vec[i]);
    }
    return res;
}

void cal(vector<int>& vec) {
    int n = vec.size();
    vector<int> sum(n+1, 0);
    for(int i=0;i<n;i++) sum[i+1]=sum[i]+vec[i];
    printf("%d", process(sum));
    for(int i=0;i<n-1;i++) {
        for(int j=1;j<n;j++) sum[j]=sum[j+1]-vec[i];
        printf(" %d", process(sum));
    }
}

int main(){
    int t, n; cin>>t;
    while(t--) {
        cin>>n;
        vector<int> vec(n);
        for(int i=0;i<n;i++) scanf("%d", &vec[i]);
        cal(vec);
        printf("\n");
    }
    return 0;
}