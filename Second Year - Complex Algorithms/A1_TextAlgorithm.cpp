#include <iostream>

using namespace std;

int tab[1000005];

int main(){
	int z;
	cin >> z;
	while(z--){
		string a;
		cin >> a;
		
		//a = '8' + a;
		
		int m = a.length();
		//cout << m << " to dlugosc"<< endl;
		
		tab[0] = 0;
		tab[1] = 0;
		
		int l = 0;
		
		for(int i=2;i<=m;i++){
			//cout << "petelka" << endl;
			while((l > 0)&&(a[l]!=a[i-1])){
				 l=tab[l];
				 //cout << "wies" << endl;
				 //cout << l  << " to i =>" << i << a[l] << " " << a[i-1]<< endl;
				 //cout << l << endl;
			}
			if(a[l]==a[i-1]) l++;
			//cout << a[l] << " " << a[i-1] << endl;
			tab[i] = l;
		}
		
		//cout << "pra" << endl;
		//for(int i=0;i<=m;i++)
		//cout << tab[i] << endl;
		
		int licz = m - tab[m];
		//cout << licz << "halo"<< endl;
		//cout << m%licz << endl;
		if((tab[m]!=0 && m%licz==0)) cout << m/licz << endl;
		else cout << 1 << endl;
	
	}
}
