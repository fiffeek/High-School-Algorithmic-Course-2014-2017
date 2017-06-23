#include <iostream>
using namespace std;
int tab[100002], wyn[100002];

int rek(int n){
	if(n==0) return 0;
	if(wyn[n]>0) return wyn[n];
	else{
		if(n==1){
		  wyn[1]=tab[1];
		  return tab[1];
		}
		if(n==2){ 
			wyn[2]=tab[1]+tab[2];
			return tab[1]+tab[2];
		}
		if(n==3){
			if(tab[1]<=tab[2] && tab[1]<=tab[3]){
				wyn[3]=tab[2]+tab[3];
				return tab[2] + tab[3];
			}
			if(tab[2]<= tab[1] && tab[2]<=tab[3]){ 
				wyn[3]=tab[3]+tab[1];
				return tab[1] + tab[3];
			}
			if(tab[3]<=tab[1] && tab[3]<=tab[2]) {
				wyn[3]=tab[2]+tab[1];
				return tab[2] + tab[1];	
			}
		}
	}
	wyn[n]=max(max(rek(n-1), rek(n-2)+tab[n]),rek(n-3)+tab[n]+tab[n-1]);
	return wyn[n];
}


int main(){
	int l;
	cin >> l;
	while(l--){
		int n;
		cin >> n;
		
		for(int i=0;i<=n;i++){
			wyn[i]=0;
			tab[i]=0;
		}
		
		int i=0;
		
		for(int i=1;i<=n;i++){
			int liczba;
			cin >> liczba;
			tab[i]=liczba;
		}
		
		int liczba=rek(n);
		cout << liczba << endl;
			
	}
}
