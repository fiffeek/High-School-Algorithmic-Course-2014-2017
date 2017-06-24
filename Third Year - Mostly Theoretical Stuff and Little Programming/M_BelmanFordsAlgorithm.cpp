#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct melanz{
	int wierz;
	double wart;
};

int zmienne[1500][1500];
vector <melanz> G[100000];
bool visited[10000];

void dfs(int a){
	visited[a] = 1;
	for(int i=0;i<G[a].size();i++){
		if(visited[G[a][i].wierz]==0){
			dfs(G[a][i].wierz);
		}
	}
}

bool belman(double srednia, int n){
//	cout << n  << " " << srednia<< "HALOI " << endl;
	double dwa[n+1];
	double d[n+1];
	for(int i=1;i<n;i++){
		dwa[i] = 0;
		d[i] = 0;
	}
	
	for(int i=1;i<n;i++){
		for(int x=1;x<n;x++){
			for(int y=0;y<G[x].size();y++){
				d[G[x][y].wierz] = min(d[G[x][y].wierz],d[x]-G[x][y].wart+srednia );
				dwa[G[x][y].wierz] = min(dwa[G[x][y].wierz],dwa[x]-G[x][y].wart+srednia );
			}
		
		}
	}
	
/*	cout << "*******" << endl;
	for(int i=0;i<=n;i++) cout << d[i] << " ";
	cout << endl;
	cout << "***********" << endl;*/
	
for(int x=1;x<n;x++){
			for(int y=0;y<G[x].size();y++){
				dwa[G[x][y].wierz] = min(dwa[G[x][y].wierz],dwa[x]-G[x][y].wart+srednia );
			}
		
		}
		
	/*	cout << "*******" << endl;
	for(int i=0;i<=n;i++) cout << dwa[i] << " ";
	//cout << endl;
	cout << "***********" << endl;*/
	
	
	for(int x=1;x<n;x++){
	//	cout << dwa[x] << " XD " << d[x] << endl;
 		if(dwa[x]<d[x]){
 			
 			//cout << "ROZNE DLA X : " << x << endl;
 			 return true;
 			 
		 }
	}
	return false;

}


int main(){
	int z;
	cin>> z;
	while(z--){
		int a;
		cin >> a;
		
		for(int i=0;i<150;i++){
			for(int j=0;j<150;j++){
				zmienne[i][j]=0;
			}
		}
		
		for(int i=0;i<1000;i++){
			G[i].clear();
			visited[i]=0;
		}
		
		int ilosc = 1;
		
		string c;
		for(int i=0;i<a;i++){
			
			cin >> c;

			if(zmienne[c[0]][c[1]]==0){
				//cout << "XD" << c[0] << " " << c[1] << endl;
				 zmienne[c[0]][c[1]] = ilosc;
				ilosc++;
			}
			
			if(zmienne[c[c.size()-2]][c[c.size()-1]]==0){
				//cout << "XD" << c[c.size()-2] << " " << c[c.size()-1] << endl;
				zmienne[c[c.size()-2]][c[c.size()-1]] = ilosc;
				ilosc++;
			}
			
			melanz M;
			M.wart = c.size();
			M.wierz = zmienne[c[c.size()-2]][c[c.size()-1]];
			
			G[zmienne[c[0]][c[1]]].push_back(M);
		}
		//cout << ilosc << endl;
		
		
		
		
		double x = 0;
		double start = 0;
		double koniec = 1000; 
		
		/*if(a==1){
			double odp = c.size();
			if(c[0]==c[c.size()-2] && c[1]==c[c.size()-1]) cout << fixed << setprecision(4)<<odp << endl;
			else cout << "NIE" << endl;
			goto kon;
		}*/
		
		if(belman(0,ilosc)==0){
			cout << "NIE" <<endl;
			goto kon;
		}
		
		/*dfs(1);
		
		for(int i=1;i<ilosc;i++){
			if(visited[i] == 0){
				//cout << i << endl;
				cout << "NIE" << endl;
				goto kon2;
			}
		}*/
		
		for(int i=0;i<28;i++){
		//	cout << x <<endl;
			x = (start+koniec)/2;
			if(belman(x,ilosc)){
				start=x;
			}
			else{
				koniec=x;
			}
			
		}
		//double PRZE = 0;
		//cout << x-PRZE << endl;
		cout << fixed << setprecision(4) << x << endl;
		//else cout << "NIE" << endl;
		//kon2:;
		kon:;
	
	}
}
