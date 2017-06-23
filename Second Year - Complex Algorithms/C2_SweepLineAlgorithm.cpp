#include <iostream>
#include <queue>

using namespace std;

struct dotab{
	int pp,kk;
	//ppilosclindopoczatku
	//kkilosclindokonca
};

struct pocomito{
	int liczba,c,id;
	bool pczyk;
	//1koniec
	//0=poczzatek
};

struct sortujemy{
      bool operator()(pocomito a, pocomito b){
              if(a.liczba!=b.liczba) return a.liczba>b.liczba;
              else{
              	return a.pczyk;
			  }
	  }
};


priority_queue<pocomito,vector<pocomito>,sortujemy> petla;
dotab tab[100005];

int main(){
	int z;
	cin >> z;
	while(z--){
		int a;
		cin >> a;
		
		for(int i=0;i<a;i++){
			int p,k,c,id;
			cin >> p >> k >> c;
			id = i;
			
			pocomito Z;
			Z.pczyk=0;
			Z.liczba=p;
			Z.c=c;
			Z.id=id;
			
			petla.push(Z);
			
			Z.pczyk=1;
			Z.liczba=k;
			Z.c=c;
			Z.id=id;
			
			petla.push(Z);
			
			tab[i].pp=0;
			tab[i].kk=0;
		}
		int ilelindotejpory=0;
		//cout << "woo" << endl;
		//cout << petla.size() << endl;
		while(petla.size()>0){
			pocomito Z;
			Z = petla.top();
			//cout << Z.liczba << " " << Z.pczyk << " " << Z.c << " " << Z.id << endl;
			if(Z.pczyk==1){
			//	cout << "TO KONIEC PRZEDIALU" << endl;
				int ilosclinwprzedziale = ilelindotejpory - tab[Z.id].pp;
				tab[Z.id].kk= Z.c - ilosclinwprzedziale;
				if(tab[Z.id].kk<0) tab[Z.id].kk=0;
				ilelindotejpory+=tab[Z.id].kk;
			//	cout << ilelindotejpory << " <=> " << ilosclinwprzedziale << endl;
			}else{
			//	cout << "TO POCZATEK PRZEDZIALU" << endl;
				tab[Z.id].pp=ilelindotejpory;
			//	cout << "TO ILOSC LIN DOT EJ PORY: " << tab[Z.id].pp << endl;
			}
			
			petla.pop();
		}
		
		cout << ilelindotejpory << endl;
	}
}
