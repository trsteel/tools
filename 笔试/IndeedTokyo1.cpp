#include <iostream>
#include <vector>

using namespace std;
int main(){
    int h,w,a,b;
    cin>>h>>w>>a>>b;
    vector<string> vec(h, "");
    for(int i=0;i<h;i++){
        cin>>vec[i];
    }
    for(int i=0;i<a;i++){
        for(string s:vec){
            for(int j=0;j<b;j++){
                cout<<s;
            }
            cout<<endl;
        }
    }
    return 0;
}
