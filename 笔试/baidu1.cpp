#include <iostream>

using namespace std;

int main(){
    int a;
    string s;
    cin>>a>>s;
    string res;
    if(a==0){
        bool isStart = true;
        for(char c:s){
            if(c=='0'){
                if(!isStart) res+=c;
            }else if(c==':'){
                res+=c;
                isStart = true;
            }else{
                res+=c;
                isStart = false;
            }
        }
        cout<<res<<endl;
    }else if(a==1){
        string tmp;
        for(char c:s){
            if(c==':'){
                while(tmp.size()<6) tmp = '0'+tmp;
                res+=tmp+':';
                tmp="";
            }
            else tmp+=c;
        }
        while(tmp.size()<6)tmp = '0'+tmp;
        res+=tmp;
        cout<<res<<endl;
    }
    return 0;
}
