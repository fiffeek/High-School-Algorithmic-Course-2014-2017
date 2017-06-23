#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

unsigned long long nwd(unsigned long long a, unsigned long long b)
{
if(a == 0) return b;
if(b == 0) return a;
if(a == b) return a;
if(a>b) return nwd(a % b, b);
if(b>a) return nwd(a, b % a);
}

main(){
      int ilosctestow;
      cin >> ilosctestow;
      while(ilosctestow--){
              int a;
              cin >> a;

              unsigned long long tablica[5000005];
              unsigned long long suma=0;
              unsigned long long iloscliczb=0;
              unsigned long long maks=0;
              unsigned long long licznik=0;
              unsigned long long min=100000000000;
              map<unsigned long long,string> Mapa;

              for(int i=0;i<a;i++){
                      unsigned long long liczba;
                      cin >> liczba;
                      if(liczba>maks) maks=liczba;
                      if(liczba<min) min = liczba;

                      if(Mapa[liczba]=="tak"){
                              tablica[licznik]=liczba;
                              licznik++;
                      }
                      else{
                              suma+=liczba;
                              iloscliczb++;
                      }


                      Mapa[liczba]="tak";

              }

              sort(tablica,tablica + licznik);
              unsigned long long sumamaksymalna=suma;
              unsigned long long iloscliczbmaks=iloscliczb;
              licznik--;
      unsigned long long wskaznikmaks=0;
              for(int i=licznik;i>=0;i--){
                      if(tablica[i]==maks){
                              sumamaksymalna+=maks;
                              iloscliczbmaks++;
                              wskaznikmaks++;
                      }
                      else break;
              }
      unsigned long long wskaznik=0;

              for(int i=0;i<=licznik;i++){
                      if(tablica[i]==min){
                              suma+=min;
                              iloscliczb++;
                              wskaznik++;
                      }
                      else break;
              }
      if(licznik!=(-1)){
                      for(int i=wskaznik;i<=licznik;i++){
                              if(suma>iloscliczb*tablica[i]){
                                      suma+=tablica[i];
                                      iloscliczb++;
                              }
                      }

                      for(int i=licznik-wskaznikmaks;i>=0;i--){
                              if(sumamaksymalna<iloscliczbmaks*tablica[i]){
                                      sumamaksymalna+=tablica[i];
                                      iloscliczbmaks++;
                              }
                      }
      }
              unsigned long long taka = nwd(sumamaksymalna,iloscliczbmaks);
              sumamaksymalna/=taka;
              iloscliczbmaks/=taka;
              unsigned long long taka2 = nwd(suma,iloscliczb);
              suma/=taka2;
              iloscliczb/=taka2;
              cout << suma << "/" << iloscliczb << " ";
              cout << sumamaksymalna << "/" << iloscliczbmaks << endl;
}
}
