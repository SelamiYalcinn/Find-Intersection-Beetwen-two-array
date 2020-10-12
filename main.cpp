#include <iostream>
#include <string>

using namespace std;

struct Ar{
  int arNew[150]{};
  int arSize{};
};

Ar ToInt(string str){
  Ar cx;
  string::size_type sz;
  int inc=0;
  auto idx=str.find(",",0);
  while(idx!=string::npos){
      int tmp=stoi(str,&sz);
      cx.arNew[inc]=tmp;
      ++inc;
      str=str.substr(sz+1);
      idx=str.find(",",0);
  }
  cx.arSize=inc;
  return cx;

}
string Process(string A[],int whOne){
  int tggle=1-whOne;//which ar size bigger than other
  string::size_type sz;
  string pnerVal{};
  if(A[whOne].back()!=',')
      A[whOne]+=",";
  if(A[tggle].back()!=',')
      A[tggle]+=",";

  Ar cx=ToInt(A[whOne]);
  Ar cy=ToInt(A[tggle]);

  for(int i=0;i<cx.arSize;++i)
  {
      for(int j=0;j<cy.arSize;++j)
      {
        if(cx.arNew[i]==cy.arNew[j]){
          pnerVal+=to_string(cx.arNew[i])+",";
          continue;
        }
      }
  }
  if(pnerVal.back()==',')
      pnerVal.erase(pnerVal.end()-1);

  return pnerVal;

}
string FindIntersection(string strArr[], int arrLength) {
    string str1=strArr[0];
    string str2=strArr[1];

    strArr[0]=str1.size()-str2.size()>0?Process(strArr,0):Process(strArr,1);

  return strArr[0];
}

int main(void) { 
  string A[] = {1,2,3,4,5","10,20,1"};//Input YOUR ARRAY(Maximum TWO ARRAY)En Fazla iki adet string dizi giriniz...
  int arrLength = sizeof(A) / sizeof(*A);
  cout << FindIntersection(A, arrLength);
  return 0;
}
