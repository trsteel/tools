//AC

#include <iostream>

using namespace std;
int main(){
    int t;
    cin>>t;
    string s,s1;
    while(t-->0){
        cin>>s;
        s1="";
        for(int i=0;i<s.size();i++){
            if(s[i]=='_'){
                s1+=s[i+1]+'A'-'a';
                i++;
            }else if(s[i]>='A' && s[i]<='Z'){
                s1+='_';
                s1+=s[i]+'a'-'A';
            }else{
                s1+=s[i];
            }
        }
        cout<<s1<<endl;
    }
}
