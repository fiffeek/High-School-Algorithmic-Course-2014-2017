#include <iostream>

using namespace std;

int tab[10000005];

void sito(){
      for(int i=2;i<=3163;i++){
              if(tab[i]==0){
                      for(int j=i*i;j<=10000005;j+=i){
                              if(tab[j]==0) tab[j]=i;
                      }
              }
      }
}

void rek(int a,int l, int ilosc){
      int z;
      if(tab[a]==0) z=a;
      else z=tab[a];

              if(l==z) ilosc++;
              else{
                      if(l!=0 && a!=1){
                               if(ilosc > 1) cout << l << "^" << ilosc << "*";
                               else cout << l << "*";
                      }

                      if(l!=0 && a==1){
                              if(ilosc > 1) cout << l << "^" << ilosc << endl;
                              else cout << l <<endl;
                      }

                      l=z;
                      ilosc=1;
              }



      if(a==1){
              return;
      }
      rek(a/z,l,ilosc);
}

int main(){
      //premade
      sito();

      int z;
      cin >> z;
      while(z--){
              int a;
              cin >> a;
              cout << a << " = ";
              if(a!=1) rek(a,0,0);
              else cout << "1" << endl;
      }
}
