/*
 * 腾讯笔试 20170404 19:00~21:00
 * 问题不难，但是C++的调试没法进行
 */

//Question 2:求字符串中逆序数，字符串中只包含A,B,C,D四个字符，要求时间复杂度为O(n)
//思路：记录当前位置之前各个字符已出现次数，然后进行统计。
#include <iostream>
using namespace std;
int main(){
    string s;
    while(cin>>s){
        int totalCnt=0;
        int cnt[4]={0,0,0,0};
        for(int i=0;i<s.size();i++){
            int cur=s[i]-'A';
            for(int j=cur+1;j<4;j++){
                totalCnt+=cnt[j];
            }
            cnt[cur]++;
        };
        cout<<totalCnt<<endl;
    }
    return 0;
}

//Question 3:按格式打印字符串，字符串长度为16的倍数，如abcdefghijklmnopqrstuvwxyzabcdef，输出格式为：
//00000000  61 62 63 64 65 66 67 68  69 6a 6b 6c 6d 6e 6f  abcdefghijklmnop
//00000010  70 71 72 73 74 75 76 77  78 79 61 62 63 64 65  qrstuvwxyzabcdef

#include <iostream>
#include <iomanip>

using namespace std;
int main(){
    string s;
    while(cin>>s){
        for(int i=0;i<s.size();i+=16){
            cout<<setw(8)<<setfill('0')<<hex<<i<<"  ";
            for(int j=i;j<i+8;j++)
                cout<<setw(2)<<setfill('0')<<hex<<(int)s[j]<<" ";
            cout<<" ";
            for(int j=i+8;j<i+16;j++)
                cout<<setw(2)<<setfill('0')<<hex<<(int)s[j]<<" ";
            cout<<" "<<s.substr(i,i+16)<<endl;
        }
    }
    return 0;
}


//Question 4:在二叉查找树中找最近公共祖先，输入k,n1,n2,n3，k表示树的高度，n1,n2,n3分别为3个节点，输出公共祖先
//测试用例：输入：4 10 11 13    输出：12

#include <iostream>

using namespace std;
int findLSA(int mid, int end, int n1,int n2,int n3){
    if(mid==0 || mid==end) return -1;
    if(n1>mid && n2>mid && n3>mid) return findLSA((mid+end)>>1,end,n1,n2,n3);
    else if(n1<mid && n2<mid && n3<mid) return  findLSA(mid>>1,mid,n1,n2,n3);
    return mid;
}
int main(){
    int k,n1,n2,n3;
    cin>>k>>n1>>n2>>n3;
    cout<<findLSA(1<<(k-1),1<<k,n1,n2,n3)<<endl;
    return 0;
}
