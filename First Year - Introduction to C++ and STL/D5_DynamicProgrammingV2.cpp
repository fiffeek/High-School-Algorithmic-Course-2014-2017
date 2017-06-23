#include <iostream>

using namespace std;
int tab[1005][1005], sum[1005], tort[1005];

unsigned long long sums(int s, int e){
	return sum[e+1]-sum[s];
}

int rek(int s, int e){
	if(tab[s][e]>0) return tab[s][e];
	if(s<e) tab[s][e]=max(sums(s,e) - rek(s+1,e), sums(s,e) - rek(s,e-1));
	else tab[s][e]=tort[s];
	
	return tab[s][e];
}


int main(){
	int z;
	cin >> z;
	while (z--){
		
		int a;
		cin >> a;
		
		for(int i=0;i<a;i++){
			for(int j=0;j<a;j++){
				tab[i][j]=0;
			}
			sum[a]=0;
		}
		
		
		for(int i=0;i<a;i++){
			int liczba;
			cin >> liczba;
			
			tort[i]=liczba;
			
			sum[i+1]=tort[i] + sum[i];
		}
		
		int s=0;
		a--;
		
		cout << rek(s,a) << endl;
		
	}
}
