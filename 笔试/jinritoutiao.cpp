//1 AC

#include <iostream>
#include <map>
using namespace std;

int main(){
    int m,n,tmp;
    cin>>m;
    map<int,int> ma;
    while(m--){
        cin>>tmp;
        ma[tmp]++;
    }
    cin>>n;
    while(n--){
        cin>>tmp;
        if(ma[tmp]>0){
            cout<<tmp<<' ';
            ma[tmp]--;
        }
    }
    return 0;
}

//3 WA 80%
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    vector<vector<string>> M(16,vector<string>(5,""));
    M[0][0]="***";
    M[0][1]="* *";
    M[0][2]="* *";
    M[0][3]="* *";
    M[0][4]="***";
    for(int i=0;i<5;i++)M[1][i]="*";
    M[2][0]="***";
    M[2][1]="  *";
    M[2][2]="***";
    M[2][3]="*  ";
    M[2][4]="***";
    M[3][0]="***";
    M[3][1]="  *";
    M[3][2]="***";
    M[3][3]="  *";
    M[3][4]="***";
    M[4][0]="* *";
    M[4][1]="* *";
    M[4][2]="***";
    M[4][3]="  *";
    M[4][4]="  *";
    M[5][0]="***";
    M[5][1]="*  ";
    M[5][2]="***";
    M[5][3]="  *";
    M[5][4]="***";
    M[6][0]="***";
    M[6][1]="*  ";
    M[6][2]="***";
    M[6][3]="* *";
    M[6][4]="***";
    M[7][0]="***";
    M[7][1]="  *";
    M[7][2]="  *";
    M[7][3]="  *";
    M[7][4]="  *";
    M[8][0]="***";
    M[8][1]="* *";
    M[8][2]="***";
    M[8][3]="* *";
    M[8][4]="***";
    M[9][0]="***";
    M[9][1]="* *";
    M[9][2]="***";
    M[9][3]="  *";
    M[9][4]="***";
    M[10][0]="   ";
    M[10][1]=" * ";
    M[10][2]="***";
    M[10][3]=" * ";
    M[10][4]="   ";
    M[11][0]="   ";
    M[11][1]="   ";
    M[11][2]="***";
    M[11][3]="   ";
    M[11][4]="   ";
    M[12][0]="   ";
    M[12][1]="* *";
    M[12][2]=" * ";
    M[12][3]="* *";
    M[12][4]="   ";
    M[13][0]="   ";
    M[13][1]="  *";
    M[13][2]=" * ";
    M[13][3]="*  ";
    M[13][4]="   ";
    M[14][0]="    ";
    M[14][1]="****";
    M[14][2]="    ";
    M[14][3]="****";
    M[14][4]="    ";
    M[15][0]="  ";
    M[15][1]="  ";
    M[15][2]="  ";
    M[15][3]="**";
    M[15][4]="**";
    map<char,int> ma;
    ma['+']=10;
    ma['-']=11;
    ma['*']=12;
    ma['/']=13;
    string s,s1,s2;
    cin>>s>>s1>>s2;
    s=s+s1+s2;
    int n1=0,n2=0;
    bool isFirst = true;
    char op=' ';
    vector<string> vec(5,"");
    for(int i=0;i<s.size();i++){
        if(s[i]==' ')continue;
        else if(s[i]>='0' && s[i]<='9'){
            int tmp=s[i]-'0';
            if(isFirst)n1=n1*10+tmp;
            else n2=n2*10+tmp;
            for(int j=0;j<5;j++){
                vec[j]+=(i>0?"  ":"")+M[tmp][j];
            }
        }else{
            isFirst = false;
            op=s[i];
            for(int j=0;j<5;j++){
                vec[j]+="  "+M[ma[s[i]]][j];
            }
        }
    }
    //输出等号
    for(int j=0;j<5;j++) vec[j]+="  "+M[14][j];
    //计算结果
    string res="";
    if(op=='+') res= to_string(n1+n2);
    else if(op=='-') res=to_string(n1-n2);
    else if(op=='*') res = to_string(n1*n2);
    else if(op=='/') res = to_string((double)n1/n2);
    for(char c:res){
        int index=0;
        if(c=='-') index=11;
        else if(c=='.') index=15;
        else index=c-'0';
        for(int j=0;j<5;j++) vec[j]+="  "+M[index][j];
    }
    for(int j=0;j<5;j++) cout<<vec[j]<<endl;
    return 0;
}

//4 WA 30%
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int countSum(vector<vector<int>> job, vector<vector<bool>> visited, int n){
    int sum=0;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<i+1;j++){
            if(visited[i][j] && visited[i+1][j] && visited[i+1][j+1])
                sum+=job[i][j];
        }
    }
    for(int j=0;j<n;j++)
        if(visited[n-1][j]) sum+=job[n-1][j];
    return sum;
}

int dfs(vector<vector<int>> job, vector<vector<bool>> visited, int n, int k, int x, int y, int diff){
    if(diff==k || x==n) return countSum(job, visited, n);
    int ans = 0;
    if(y==x){
        ans=max(ans, dfs(job,visited,n,k,x+1,0,diff));
        visited[x][y]=true;
        ans=max(ans, dfs(job,visited,n,k,x+1,0,diff+1));
        visited[x][y]=false;
    }
    else if(y<x){
        ans = max(ans, dfs(job,visited,n,k,x,y+1,diff));
        visited[x][y]=true;
        ans = max(ans, dfs(job,visited,n,k,x,y+1,diff+1));
        visited[x][y]=false;
    }
    return ans;
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> job(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            cin>>job[i][j];
        }
    }
    if(k>=n) cout<<countSum(job, vector<vector<bool> >(n,vector<bool>(n,true)), n)<<endl;
    else cout<<dfs(job,vector<vector<bool>>(n,vector<bool>(n,false)),n,k,0,0,0)<<endl;
    return 0;
}
