#include <iostream>

using namespace std;

int tab[10000005];
int a;

int zachlan(int p){
	//cout << "zachlan od p" << endl;
//cout << p << endl;
		int odp = 0;		
		int sum =0;
		for(int i=0;i<a;i++){
			sum+=tab[i];
			if(sum>p){
				sum=tab[i];
				odp++;
			}
		}
		if(sum<=p) odp++; 
		//cout << odp << endl;
		
		return odp;
}

int main(){
	int z;
	cin >> z;
	while(z--){
		int k;
		cin >> a >> k;
		
		int koniec = 0;
		int max = 0;
		
		for(int i=0;i<a;i++){
			cin >> tab[i];
			koniec+=tab[i];
			if(tab[i]>max) max = tab[i]; 
		}
		
		int wejscie = max;
		//int a=5;
		while(wejscie<=koniec){
		//	cout << endl;
			//cout << koniec << " " << wejscie << endl;
		//	cout << (koniec+wejscie )/ 2 << endl;
			//cout << zachlan((wejscie+koniec) / 2) << endl; 
			if (zachlan((wejscie + koniec )/2) > k) wejscie = ((wejscie+koniec)/ 2) + 1;
			else{
				koniec = ((wejscie + koniec )/ 2) - 1;
			} 
		}
		//zachlan(16);
		cout << wejscie << endl;
	
	}
}
