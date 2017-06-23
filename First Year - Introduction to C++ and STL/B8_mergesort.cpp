#include <iostream>
#include <algorithm>
using namespace std;
int tablica[100005],prze[100005];

void scalanie(int poczatek, int srodek, int koniec){
	int p1 = poczatek;
	int s1 = srodek;
	int k1 = koniec;
	
	for(int i=poczatek;i<=koniec;i++){
		if(p1==srodek || (s1<=koniec && tablica[p1]>=tablica[s1])){
			prze[i]=tablica[s1];
			s1++;
		}else{
			prze[i]=tablica[p1];
			p1++;
		}
	}
	
	for(int i=poczatek;i<=koniec;i++) tablica[i] = prze[i];
}

void merge(int poczatek,int koniec){
	int srodek = (poczatek+koniec+1)/2;
	if(srodek-poczatek > 1) merge(poczatek,srodek-1);
	if(koniec-srodek > 0) merge(srodek,koniec);
	scalanie(poczatek,srodek,koniec);
}

int main(){
    int a,h;

    cin >> a >> h;


    int n;
    for(int i=0;i<a;i++){
        cin >> n;
        tablica[i]=n;
    }

     merge(0,a-1);
     a--;


    int iloscpolek=0;
    int i=0;

    while(i<a){
        if(tablica[a]+tablica[i]<=h){
            i++;
            iloscpolek++;
        }
        else{
            iloscpolek++;
        }
        a--;
    }
if(i==a) iloscpolek++;
cout << iloscpolek << endl;

}
