#include <iostream>
#include <map>

using namespace std;

int tab[500005],a;
map <int, int> mapa;


void rek(int x){
    int taki=x-1,b=2*x-1;

    for(int i=b;i>=2;i-=2){
        if(tab[i] > tab[i-1]) tab[taki] = tab[i];
        else tab[taki] = tab[i-1];
        taki--;
    }	
}

int maxprzedzial(int x, int l1, int l2){
//cout << "Aa" << endl;
      int maax=0;
      l1+=x;
      l2+=x;
      //cout << "to x" << x << endl;
//cout << l1 << " a " << l2 << endl;
//cout << tab[l1] << " " << tab[l2] << endl;
      if(tab[l1]>tab[l2]) maax = tab[l1];
      else maax = tab[l2];
		//cout << maax << "Aa" << endl;

      while((l1/2)!=(l2/2)){
              if(l1%2==0) if(maax<tab[l1+1]) maax=tab[l1+1];
              if(l2%2==1) if(maax<tab[l2-1]) maax=tab[l2-1];
              l1/=2;
              l2/=2;
      }

      return mapa[maax];
}


int domina(int pocz, int koniec, int x){
//	cout << pocz << " " << koniec << " "<< x << endl;
	if(pocz > koniec) return 0;
	
	int liczba=maxprzedzial(x,pocz,koniec);
//	return liczba;
	return min(domina(pocz,liczba-1,x),domina(liczba+1,koniec,x)) + 1;
}

int main(){
	cin  >> a;
	//a=7;
	int x = 1;
	while(x<a) x = x*2;
		
	mapa.clear();
	//cout << "A" << endl;
	for(int i=x;i<x+a;i++){
		if(i<x+a){
			 cin >> tab[i];
			 //tab2[tab[i]] = i-x;
			 mapa[tab[i]] = i-x;
		}
		else tab[i] = 0;
	}
	
	rek(x);
	
/*	for(int i=0;i<2*x;i++) cout << tab[i] << " ";
	cout << endl;*/
	
	//cout << "9" << endl;
	cout << domina(0,a-1,x) << endl;
	//cout << domina(0,1,x) << endl;
	//cout << maxprzedzial(x,0,1) << endl;
//	cout << domina(3,6,x) << endl;
	
}
