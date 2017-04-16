// WA 30%

#include <iostream>
#include <map>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

double computeP(vector<double> p, int m, int n, double pre, int index, int t){
    if(index>n) return 0;
    if(m==t){
        for(int i=index;i<n;i++) pre*=（1-p[i]);
        return pre;
    }else if(index<n){
        return computeP(p, m, n, pre*p[index], index+1, t+1)+computeP(p, m, n, pre*(1-p[index]), index+1, t);
    }
    return 0;
}

int main(){
    int n,m;
    cin>>n>>m;
    vector<double> p(n,0);
    for(int i=0;i<n;i++) cin>>p[i];
    cout<<computeP(p, m, n, 1.0, 0, 0)<<endl;
    return 0;
}
