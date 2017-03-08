class Solution{
public:
  int myAtoi(string str){
    if(str=="") return 0;
    int iRes = 0, iResPre = 0;
    bool isNeg = false, isBegin=true;
    for(auto i=0;i<str.size();i++){
      if(str[i]>='0' && str[i]<='9'){
        isBegin = false;
        iRes = iResPre*10+(str[i]-'0');
        if(iRes/10!=iResPre) return isNeg?INT_MIN:INT_MAX;
        iResPre = iRes;
      }
      else if(isBegin){
        if(str[i]==' ') continue;
        else if(str[i]=='-') isNeg=true;
        else if(str[i]!='+') return 0;
        isBegin = false;
      }
      else return isNeg?-iRes:iRes;
    }
    return isNeg?-iRes:iRes;
  }
}
