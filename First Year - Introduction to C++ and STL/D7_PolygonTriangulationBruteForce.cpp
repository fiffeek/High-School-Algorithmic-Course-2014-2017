#include <iostream>
#include <vector>

using namespace std;

vector < pair < int , int > > V;
unsigned long long T[205][205];
unsigned long long K[205][205];

unsigned long long maxx = 1844674407370955161;

unsigned long long boki;


unsigned long long kwadraty(unsigned long long a, unsigned long long b){
	return ((V[a].first-V[b].first)*(V[a].first-V[b].first) + (V[a].second-V[b].second)*(V[a].second-V[b].second));
}

void f(int a){
	for(int i=0;i<a;i++){
		for(int j=0;j<a;j++){
			cout << K[i][j] << " ";
		}
		cout << endl;
	}
}

void wyprek(int a, int b){
	if(a+1==b) return;
	if(a!=0 || b!=boki-1) cout << a << " " << b << " ";
	
	unsigned long long k = T[a][b];
	wyprek(a,k);
	wyprek(k,b);
}

unsigned long long funkcja(int a){
	
	V.clear();
	
	for(int i=0;i<a;i++){
		//cout << "1" << endl;
		for(int j=0;j<a;j++){
			T[i][j]=-2;
			K[i][j]=maxx;
			//cout << "2" << endl;
		}
		K[i][i]=0;
		K[i][i+1]=0;
	}
	
	//f(a);
	//cout << endl;
	for(int punkty=3;punkty<a+1;punkty++){
			//cout << "3" << endl;
		for(int poczatek=0;poczatek<a-punkty+1;poczatek++){
			//	cout << "4" << endl;
			for(int k=poczatek+1;k<poczatek+punkty-1;k++){
				//	cout << punkty << " " << poczatek << " " << k << endl;
				//cout << "wartosci" << endl;
				//cout << K[poczatek][k] + K[k][poczatek+punkty-1] + kwadraty(poczatek,poczatek+punkty-1) << " " << K[poczatek][poczatek+punkty-1] << endl;
				//cout << "====" << endl;
				K[poczatek][poczatek+punkty-1]= min(K[poczatek][poczatek+punkty-1], K[poczatek][k] + K[k][poczatek+punkty-1] + kwadraty(poczatek,poczatek+punkty-1));
				//cout << 
				if(K[poczatek][poczatek+punkty-1] == (K[poczatek][k] + K[k][poczatek+punkty-1] + kwadraty(poczatek,poczatek+punkty-1))){
					T[poczatek][poczatek+punkty-1] = k;
				}
			}
		}
	}
	
	//f(a);
	
	cout << K[0][a-1] - kwadraty(0, a-1) << " ";	
	wyprek(0,a-1);
	cout << endl;
	
}

int main(){
	int z;
	cin >> z;
	while(z--){
		int a;
		cin >> a;
		
		boki=a;
		
		for(int i=0;i<a;i++){
			pair <int , int > liczba;
			cin >> liczba.first >> liczba.second;
			V.push_back(liczba);
		}
		
		funkcja(a);		
	}	
}


