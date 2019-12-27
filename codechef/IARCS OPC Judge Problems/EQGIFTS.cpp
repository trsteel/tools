/**
 * 关键点: 用差值代替数值对，问题转化为将一个数组拆分为和接近的两个数组，用背包问题方法解决
 **/
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

int cal(vector<int>& vec) {
    int n = vec.size(), sum = 0;
    for(int i: vec) sum+=i;
    int avg = sum/2, res = 0;
    unordered_set<int> dp;
    dp.insert(0);
    for(int i=0;i<n;i++) {
        vector<int> add;
        for(int j: dp) {
            int ans = j+vec[i];
            if(ans == avg) return abs(2*ans-sum);
            if(ans<=avg && dp.count(ans)==0) {
                res = max(res, ans);
                add.push_back(ans);
            }
        }
        for(int i: add) dp.insert(i);
    }
    return abs(sum-2*res);
}

int main(){
    int n; cin>>n;
    vector<int> vec(n);
    int a, b, d;
    for(int i=0;i<n;i++){
        cin>>a>>b; vec[i] = abs(a-b);
    }
    cout<<cal(vec)<<endl;
    return 0;
}