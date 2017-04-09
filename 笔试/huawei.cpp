/*
 * 华为笔试20170407 第三题 任务调度 通过率：16.7%
 * 输入格式： 任务ID.优先级[0~200].开始时间.运行时间
 * 输入样例： [1.80.1.10]|[2.10.11.15]|[3.50.21.15]|[4.120.31.10]|[5.100.41.10]
 * 输出：前200秒任务调度序列 -- 任务ID.运行时间(ID为0代表无任务运行)
 * 输出样例： 0.1|1.10|2.10|3.10|4.10|5.10|2.5|0.144
 */


#include <iostream>
#include <vector>

using namespace std;

void change(vector<vector<int>>& vec,int* curTime,string& s){
        sort(vec.begin(),vec.end(),[](vector<int> v1,vector<int> v2){
            return ((v1[2]<v2[2]) || ((v1[2]==v2[2]) && (v1[1]>v2[1])));
        });
    int i=0;
    for(;i<4;i++){
        if(vec[i][3]==0)continue;
        if(vec[i][2]>*curTime){
            s+="0."+to_string(vec[i][2]-*curTime)+"|";
            //cout<<0<<"."<<(vec[i][2]-*curTime)<<"|";
            *curTime=vec[i][2];
        }
        //执行i
        int tmp=vec[i+1][2]-vec[i][2];
        if(vec[i][3]==tmp){
            s+=to_string(vec[i][0])+"."+to_string(tmp)+"|";
            //cout<<vec[i][0]<<"."<<tmp<<"|";
            vec[i][3]=0;
            *curTime+=tmp;
        }
        else if(vec[i][3]<tmp){
            s+=to_string(vec[i][0])+"."+to_string(vec[i][3])+"|";
            //cout<<vec[i][0]<<"."<<vec[i][3]<<"|";
            vec[i][3]=0;
            s+="0."+to_string(tmp-vec[i][3])+"|";
            //cout<<0<<"."<<(tmp-vec[i][3])<<"|";
            *curTime+=tmp;
        }
        else{
            s+=to_string(vec[i][0])+"."+to_string(tmp)+"|";
            //cout<<vec[i][0]<<"."<<tmp<<"|";
            vec[i][3]-=tmp;
            *curTime+=tmp;
            //计算下一个位置
            int j=i+1;
            for(;j<5;j++){
                if(vec[j][1]<=vec[i][1]){
                    vec[i][2]=vec[j-1][2]+vec[j-1][3];
                    vec[j][2]=vec[i][2]+vec[i][3];
                }
            }
            if(j==5)vec[i][2]=vec[4][2]+vec[4][3];
        }
    }
    if(i==4 && vec[i][3]!=0){
        //执行5
        if(vec[i][2]>*curTime){
            s+="0."+to_string(vec[i][2]-*curTime)+"|";
            //cout<<0<<"."<<(vec[i][2]-*curTime)<<"|";
            *curTime+=(vec[i][2]-*curTime);
        }
        s+=to_string(vec[i][0])+"."+to_string(vec[i][3])+"|";
        //cout<<vec[i][0]<<"."<<vec[i][3]<<"|";
        *curTime+=vec[i][3];
        vec[i][3]=0;
    }
}
//[1.80.1.10]|[2.10.11.15]|[3.50.21.15]|[4.120.31.10]|[5.100.41.10]
int main(){
    vector<vector<int>> vec(5,vector<int>(4,0));
//    for(int i=0;i<5;i++){
//        for(int j=0;j<4;j++){
//            cin>>vec[i][j];
//        }
//    }
        scanf("[%d.%d.%d.%d]",&vec[0][0],&vec[0][1],&vec[0][2],&vec[0][3]);
        for(int i=1;i<5;i++){
            scanf("|[%d.%d.%d.%d]",&vec[i][0],&vec[i][1],&vec[i][2],&vec[i][3]);
        }
    int curTime=0;
    string s;
    while(vec[0][3]!=0
          || vec[1][3]!=0
          || vec[2][3]!=0
          || vec[3][3]!=0
          || vec[4][3]!=0) {
        change(vec, &curTime,s);
    }
    if(curTime<200)
        cout<<s<<0<<"."<<(200-curTime)<<endl;
    else cout<<s.substr(0,s.size()-1)<<endl;
    return 0;
}
