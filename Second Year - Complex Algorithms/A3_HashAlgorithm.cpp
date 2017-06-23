#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const unsigned long long N=50000;
const unsigned long long P=1e6 + 3;
unsigned long long tab[N];
vector <unsigned long long> S;
unsigned long long a;

bool prog(unsigned long long  liczba){
//	cout << "wbij" << endl;
      S.clear();
      unsigned long long  zmienna = 0;
      unsigned long long  maxx = 1;
  	  unsigned long long razy=1;
  	  
  	  for(int j=1;j<liczba;j++){
  	  	maxx*=P;
	  }
  	  
  	 // cout << maxx << "MAXX"<< endl;
      for(int i=0;i+1<=liczba;i++){
      	      zmienna*=P;
              zmienna+=tab[i];
	  }
	  //cout << zmienna << "daa" << endl;
      S.push_back(zmienna);

      unsigned long long  obrot = 1;
      for(unsigned long long i = 1;i<=(a-liczba);i++){
              zmienna-=(maxx*tab[i-1]);
              zmienna*=P;
              zmienna+=(tab[i+liczba-1]);
              //cout << "Zemi" << zmienna << endl;
              S.push_back(zmienna);
              obrot++;
      }

       sort(S.begin(),S.end());
	  
	  for(int i=1;i<S.size();i++){
	  		if(S[i]==S[i-1]) return true;
	  }
	  
	  return false;
}

int main(){
      ios_base::sync_with_stdio(0);
      int z;
      cin >> z;
      while(z--){
              cin >> a;

              for(int i=0;i<a;i++) cin >> tab[i];

              unsigned long long  wejscie = 1;
              unsigned long long  koniec = a;

        while(wejscie<=koniec){
        //    cout << wejscie << " " << koniec << endl;
                      if (prog((wejscie + koniec )/2)){
                          wejscie = ((wejscie+koniec)/ 2) + 1;
                      }else koniec = ((wejscie + koniec )/ 2) - 1;
                              //      cout << wejscie << " " << koniec << endl;

              }
                      cout << wejscie << endl;
      }
}
