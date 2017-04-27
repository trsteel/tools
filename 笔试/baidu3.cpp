/* 测试用例
10
60 30
120 28
180 35
240 34
300 40
360 31
420 28
480 2
540 42
600 30
2
gt avg 7200
lt min 300
*/

#include <iostream>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;

int minmaxgl(vector<pair<int,int>> vect, bool gt, bool mi, int l){
    vector<pair<int,int>> vec(vect);
    if(mi){
        sort(vec.begin(), vec.end(),[](pair<int,int> p1, pair<int,int> p2){
            return p1.second<p2.second;
        });
    }else{
        sort(vec.begin(), vec.end(),[](pair<int,int> p1, pair<int,int> p2){
            return p1.second>p2.second;
        });
    }
    int ans = 0;
    for(int i=1;i<(int)vect.size();i++){
        for(int j=0;j<(int)vec.size();j++){
            if(vec[j].first<vect[i].first && vec[j].first>(vect[i].first-l)){
                bool cur = (vec[j].second>vect[i].second)^gt;
                if(vec[j].second==vect[i].second) cur =false;
                if(cur){
                    cout<<vect[i].first<<" "<<vect[i].second<<" "<<vec[j].second<<endl;
                    ans++;
                }
                break;
            }
        }
    }
    return ans;
}

int avggl(vector<pair<int,int>> vect, bool gt, int l){
    int ans = 0;
    vector<pair<int,double>> vec(vect.size(),pair<int,double>(0,0));
    double sum=0;
    for(int i=1;i<vect.size();i++){
        sum+=vect[i-1].second;
        vec[i].first = vect[i].first;
        vec[i].second = sum;
    }
    for(int i=1;i<(int)vect.size();i++){
        for(int j=0;j<i;j++){
            if(vec[j].first>=(vect[j].first-l)){
                double avg = (vec[i].second-vec[j].second)/(i-j);
                bool cur = (vect[i].second>avg)^gt;
                if(vect[i].second-avg==0) cur = false;
                if(cur){
                    //cout<<vect[i].first<<" "<<vect[i].second<<" "<<avg<<endl;
                    ans++;
                }
                break;
            }
        }
    }
    return ans;
}


int main(){
    int n,c,l;
    string r, f;
    cin>>n;
    vector<pair<int,int>> vec(n,pair<int,int>(0,0));
    for(int i=0;i<n;i++){
        cin>>vec[i].first>>vec[i].second;
    }
    cin>>c;
    while(c--){
        cin>>r>>f>>l;
        if(f=="avg"){
            cout<<avggl(vec, r=="gt", l)<<endl;
        }else{
            cout<<minmaxgl(vec, r=="gt", f=="min", l)<<endl;
        }
    }
    return 0;
}
