#include <iostream>

using namespace std;

int tab[80][80];
int wyn[80][80];
int bufor[80][80];
int wektor[1][80];
int wynik[1][80];

void mnozeniewtab(int k){
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			int suma=0;
			for(int p=0;p<k;p++){
				suma+=tab[i][p]*wyn[p][j];
			}
			
			bufor[i][j]=suma%1000;
			while(bufor[i][j]<0) bufor[i][j]+=1000;	
		}
	}
}

void czyszczenie(int k){
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			tab[i][j]=0;
			wyn[i][j]=0;
			bufor[i][j]=0;
		}
		wektor[0][i]=0;
		wynik[0][i] = 0;
	}
}

void mnozenietabtab(int k){
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			int suma=0;
			for(int p=0;p<k;p++){
				suma+=tab[i][p]*tab[p][j];
			}
			
			bufor[i][j]=suma%1000;
			while(bufor[i][j]<0) bufor[i][j]+=1000;			
		}
	}

}

void mnozeniew(int k){
	for(int i=0;i<k;i++){
			int suma=0;
			for(int p=0;p<k;p++){
				suma+=tab[i][p]*wektor[0][p];
			}
			wynik[0][i]=suma%1000;
			while(wynik[0][i]<0) wynik[0][i]+=1000;			
	}
}

void jedynka(int k){
	for(int i=1;i<k;i++){
		for(int j=0;j<k;j++){
			if((i-j)==1) tab[i][j]=1;
			else tab[i][j]=0;
		}
	}
}

void ustawieniewyniku(int k){
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			wyn[i][j]=0;
		}
		wyn[i][i]=1;	
	}
}

void przepisywaniebufordowynik(int k){
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			wyn[i][j]=bufor[i][j];
		}
	}
}

void przepisywaniebufordotab(int k){
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			tab[i][j]=bufor[i][j];
		}
	}
}

void przepisywaniewyndotab(int k){
	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){
			tab[i][j]=wyn[i][j];
		}
	}
}

void macierzdok(int k,int m){
	int potega = m-k;

	ustawieniewyniku(k);
	
	while(potega>0){
		if(potega & 1){
			mnozeniewtab(k);
			przepisywaniebufordowynik(k);
		}
		potega >>= 1;
		if(potega==0) goto here;
		mnozenietabtab(k);
		przepisywaniebufordotab(k);
	}
	here:;
	przepisywaniewyndotab(k);
}

int program(int k, int m){
	jedynka(k);
	
	macierzdok(k,m);
	
	mnozeniew(k);
	if(wynik[0][0]<100 && wynik[0][0]>9) cout << "0" << wynik[0][0]<<endl;	
	else if(wynik[0][0]<10) cout << "00" << wynik[0][0] << endl;
	else{
		wynik[0][0]%=1000;
		cout << wynik[0][0] << endl;
	}
}


int main(){
	int z;
	cin >> z;
	while(z--){
		int k,m;
		cin >> k >> m;
		czyszczenie(k);
		
		for(int i=0;i<k;i++){
			cin >> tab[0][i];
			tab[0][i]%=1000;
			while(tab[0][i]<0) tab[0][i]+=1000;
		}
		
		for(int i=0;i<k;i++){
			cin >> wektor[0][i];
			wektor[0][i]%=1000;
			while(wektor[0][i]<0) wektor[0][i]+=1000;
		}
		
		if(m<=k){
			wynik[0][0] = wektor[0][k-m];
			if(wynik[0][0]<100 && wynik[0][0]>9) cout << "0" << wynik[0][0]<<endl;	
			else if(wynik[0][0]<10) cout << "00" << wynik[0][0] << endl;
			else{
				wynik[0][0]%=1000;
				cout << wynik[0][0] << endl;
			}
		}else{
			program(k,m);
		}
	}
}
