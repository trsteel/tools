 /*
 * hiho一下140 1.清理海报
 * WA 40/100
 */

#include <vector>
#include <iostream>
using namespace std;

bool judgAngleCover(int* matrix, int i, int j, bool* isAngleCoverd){
    bool x1 = matrix[i*4]>matrix[j*4] && matrix[i*4]<matrix[j*4+2];
    bool y1 = matrix[i*4+1] > matrix[j*4+1] && matrix[i*4+1] < matrix[j*4+3];
    bool x2 = matrix[i*4+2]>matrix[j*4] && matrix[i*4+2]<matrix[j*4+2];
    bool y2 = matrix[i*4+3] > matrix[j*4+1] && matrix[i*4+3] < matrix[j*4+3];
    bool* anCover = new bool[4]{(x1&&y1) || isAngleCoverd[0],
        (x1&&y2) || isAngleCoverd[1],
        (x2&&y2)||isAngleCoverd[2],
        (x2&&y1)||isAngleCoverd[3]};
    bool bRes = anCover[0]&&anCover[1]&&anCover[2]&&anCover[3];
    if(!bRes) for(int k=0;k<4;k++) isAngleCoverd[k] = anCover[k];
    delete [] anCover;
    return bRes;
}

bool judgeContentCover(int* matrix, vector<int> vec, int j){
    for(auto i=0;i<vec.size();i++){
        if(matrix[4*i+2]>matrix[4*j]
           && matrix[4*i]< matrix[4*j+2]
           && matrix[4*i+3]>matrix[4*j+1]
           && matrix[4*i+1]<matrix[4*j+3])
            return true;
    }
    return false;
}

int main()
{
    int w, h, n;
    cin>>w>>h>>n;
    if(w<=0 || h<=0 || n<=0){
        cout<<"输入不合法"<<endl;
        return -1;
    }
    if(n==1){
        cout<<"1 1"<<endl;
        return 0;
    }
    int* matrix = (int*)malloc(4*n*sizeof(int));
    for(int i=0;i<n*4;i++){
        cin>>matrix[i];
    }
    unsigned long ans=0,  k=0;
    //二重循环，记录每次的海报序号
    for(int i=0;i<n;i++){
        vector<int> vec;
        vec.push_back(i);
        bool* isAngleCoverd = new bool[4]{false};
        for(int j=i+1;j<n;j++){
            //如果j与s中任意一张海报相交且i的四角未被完全覆盖，则加入s
            //判断相交
            if(judgeContentCover(matrix, vec, j)){
                if(!judgAngleCover(matrix, i, j, isAngleCoverd))
                    vec.push_back(j);
            }
        }
        if(vec.size()>ans){
            ans = vec.size();
            k = i+1;
        }
    }
    cout<<ans<<" "<<k<<endl;
    free(matrix);
    return 0;
}
