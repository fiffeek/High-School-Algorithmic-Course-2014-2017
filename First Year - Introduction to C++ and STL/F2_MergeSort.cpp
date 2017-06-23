#include <iostream>

using namespace std;

int tab[100005],prze[100005];
unsigned long long odp = 0;

void scalanie(int poczatek, int srodek, int koniec){
	int p1 = poczatek;
	int s1 = srodek;
	int k1 = koniec;
	
	//cout << "scalanie " << poczatek << " " << srodek << " " << koniec << endl;
	
	for(int i=poczatek;i<=koniec;i++){
		if(p1==srodek || (s1<=koniec && tab[p1]>=tab[s1])){
			prze[i]=tab[s1];
			odp+=p1-poczatek;
			s1++;
		}else{
			prze[i]=tab[p1];
		//	cout << i-p1 << " top p1" << endl;
			p1++;
		}
	}
	
	for(int i=poczatek;i<=koniec;i++) tab[i] = prze[i];
}

void merge(int poczatek,int koniec){
	int srodek = (poczatek+koniec+1)/2;
	if(srodek-poczatek > 1) merge(poczatek,srodek-1);
	if(koniec-srodek > 0) merge(srodek,koniec);
	scalanie(poczatek,srodek,koniec);
}

int main(){
	int z;
	cin >> z;
	while(z--){
		odp = 0;
		int a;
		cin >> a;
		
		for(int i=0;i<a;i++){
			cin >> tab[i];
			prze[i] = 0;
		}
		
		merge(0,a-1);
		
		for(int i=a-1;i>=0;i--) cout << tab[i] << " ";
		cout << endl;
		
		cout << odp << endl;
	}
}
