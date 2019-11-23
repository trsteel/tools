#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n; cin>>n;
    long a=0, b=0, c=0;
    unordered_map<long, long> create, pay, cancel;
    while(n--) {
        string s; long id, amount;
        cin>>s>>id;
        if(s=="CREATE") {cin>>amount; create[id] = amount; a+=amount;}
        else if(s=="PAY") {
            b+=create[id];
            a-=create[id];
            pay[id]=create[id]; 
            create.erase(id);
        } else if(s=="CANCEL") {
            c+=create[id];
            a-=create[id];
            cancel[id]=create[id]; 
            create.erase(id);
        }
    }
    cout<<b<<" "<<c<<" "<<a<<endl;
    return 0;
}