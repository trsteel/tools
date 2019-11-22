#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <string>
using namespace std;
int main(){
    string ssDate, ssTime, seDate, seTime;
    cin>>ssDate>>ssTime>>seDate>>seTime;
    tm tm_s, tm_e;
    time_t t_s, t_e;
    strptime((ssDate+" "+ssTime).c_str(),"%Y-%m-%d %H:%M:%S", &tm_s);
    strptime((seDate+" "+seTime).c_str(),"%Y-%m-%d %H:%M:%S", &tm_e);
    
}
