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
  int tggle=1-whOne;//Small size array index with small than other(Küçük olan array indexi tggle'a atandi)
  string::size_type sz;
  string pnerVal{};//member init...
  if(A[whOne].back()!=',')//Add ',' For searching algorithm(Arama fonksiyonunun sağlıklı çalışması için ',' eklendi)
      A[whOne]+=",";
  if(A[tggle].back()!=',')//Add ',' For searching algorithm(Arama fonksiyonunun sağlıklı çalışması için ',' eklendi)
      A[tggle]+=",";

  Ar cx=ToInt(A[whOne]);//All member convert to int and add to cx.arNew(Büyük olan diziyi integer olarak cx.arNew dizisine aktardık)
  Ar cy=ToInt(A[tggle]);//All member convert to int and add to cy.arNew(Küçük olan diziyi integer olarak cy.arNew dizisine aktardık)

  for(int i=0;i<cx.arSize;++i)//For compare(Elemanlar karşılaştırılacak)
  {
      for(int j=0;j<cy.arSize;++j)
      {
        if(cx.arNew[i]==cy.arNew[j])
        {
          pnerVal+=to_string(cx.arNew[i])+",";//Add new ar if first val== second val
          continue;
        }
      }
  }
  if(pnerVal.back()==',')
      pnerVal.erase(pnerVal.end()-1);

  return pnerVal;

}
string FindIntersection(string strArr[], int arrLength) {
    string str1=strArr[0];//First string member(Dizinin İlk string elemanı)
    string str2=strArr[1];//Second string member(Dizinin İkinci string elemanı)

    strArr[0]=str1.size()-str2.size()>0?Process(strArr,0):Process(strArr,1);
    //Whicg One Bigger than other(Array ve büyük dizinin indexi ile İşlem fonksiyonuna gidiliyor)

  return strArr[0];
}

int main(void) { 
  string A[] = {1,2,3,4,5","10,20,1"};//Input YOUR ARRAY(Maximum TWO ARRAY)En Fazla iki adet string dizi giriniz...
  int arrLength = sizeof(A) / sizeof(*A);
  cout << FindIntersection(A, arrLength);
  return 0;
}
