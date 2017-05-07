/*
WA 30.77%
测试用例：
输入：
    Produces a printable string reoresentation of a dictionary
    784
输出：
    string
*/

#include <iostream>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
vector<string> tvec = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int countSub(string s1, string s2){
    if(s1=="" || s2=="") return 0;
    vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,0));
    int ans = 0;
    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s2.size();j++){
            if(tvec[s1[i]-'0'].find(s2[j])<tvec[s1[i]-'0'].size()){
                dp[i+1][j+1]=dp[i][j]+1;
                ans = max(ans,dp[i+1][j+1]);
            }
        }
    }
    return ans;
}
int main(){
    vector<string> dict;
    string s;
    while(cin>>s){
        if(s[0]>='0' && s[0]<='9') break;
        dict.push_back(s);
    }
    int maxLen=0;
    string ans="";
    for(string d:dict){
        int cnt =countSub(s,d);
        cout<<d<<cnt<<endl;
        if(cnt>maxLen){
            maxLen=cnt;
            ans=d;
        }
    }
    cout<<ans<<endl;
    return 0;
}
