#include <algorithm>
#include <iostream>

using namespace std;

int maxx=2000000005;

int main(){
	int z;
	cin >> z;
	while(z--){
		int dl;
		cin >> dl;
		
		int a[100005];
		int t[100005];
		
		for(int i=0;i<dl+5;i++){
			t[i]=maxx;
			a[i]=0;
		}
		
		for(int i=0;i<dl;i++){
			int liczba;
			cin >> liczba;
			a[i]=liczba;
		}
		
		for(int i=0;i<dl;i++){
			int x = lower_bound(t, t+dl, a[i]) - t;
			t[x] = a[i];
		}
		
		int wynik;
		for(int i=0;i<dl;i++){
			if(t[i]!=maxx){
				wynik=i;
			}else break;
		}
		
		//for(int i=0;i<dl;i++) cout << t[i] << " ";
		//cout << endl;
		wynik++;
		//indeksowanie
		
		cout << dl - wynik << endl;		
	}
	
}
