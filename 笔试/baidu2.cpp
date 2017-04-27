#include <iostream>
#include <map>
#include <vector>
#include <math.h>
#include <iomanip>
using namespace std;

double countDis(pair<int,int> p1, pair<int,int> p2){
    int x = p1.first-p2.first;
    int y = p1.second-p2.second;
    return sqrt(x*x+y*y);
}

int main(){
    string s;
    cin>>s;
    double ans = 0;
    if(s.size()>1){
        map<char, pair<int,int>> ma;
        vector<string> vec = {"zxcvbnm,./","asdfghjkl;","qwertyuiop"};
        for(int i=0;i<3;i++){
            for(int j=0;j<vec[i].size();j++){
                ma[vec[i][j]] = pair<int,int>{i,j};
            }
        }
        for(int i=1;i<s.size();i++){
            ans+=countDis(ma[s[i-1]], ma[s[i]]);
        }
    }
    cout<<setiosflags(ios::fixed)<<setprecision(5)<<ans<<endl;
    return 0;
}
