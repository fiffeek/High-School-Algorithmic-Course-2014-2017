#include <iostream>
#include <vector>

using namespace std;

struct A{
	int l;
	char znak;
};

vector <int> G[500005];
A GRAF[505][505];
int m1[500005];
int m2[500005];
bool visited[500005];
bool krop[500005];

bool dfs(int a){
	//cout << "WBIJ" << a << endl;
      if(a==(-1)) return true;
      if(visited[a]==1) return false;
      visited[a]=1;
     // cout << "WIERZ " << a << " SYN : " << G[a].size() << endl;
      for(int i=0;i<G[a].size();i++){
              if(dfs(m2[G[a][i]])){
                      m1[a]=G[a][i];
                      m2[G[a][i]]=a;
                      return true;
              }
      }
      return false;
}

int main(){
      int z;
      cin >> z;
      while(z--){
              int n,m;
              cin >> n >> m;
             // cout << "AAEW" << endl;
				
              for(int i=0;i<=(2*n*m);i++){
              //	cout << i << endl;
                      G[i].clear();
                      krop[i]=0;
              }
             // cout << "CPUN" << endl;

				int ilosc = 0;

              for(int i=0;i<n;i++){
                      for(int j=0;j<m;j++){
                      	char c;
                      	cin >> c;
                      	
                      	GRAF[i][j].znak = c;
                      	GRAF[i][j].l=ilosc;
                      	if(c=='.') krop[ilosc] = 1;
                      	ilosc++;
					  }
              }
              //cout << "WERR" << ilosc << endl;
             // cout << "ZATOR" <<endl;
              
              for(int i=0;i<n;i++){
                      for(int j=0;j<m;j++){
                      	if(GRAF[i][j].znak=='C'){
                      		if( i>=1){
                      			if(GRAF[i-1][j].znak=='B'){
                      				G[GRAF[i][j].l].push_back(GRAF[i-1][j].l);
                      			  G[GRAF[i-1][j].l].push_back(GRAF[i][j].l);
								  } 
							  }
							if(((i+1)<n)){
								if( GRAF[i+1][j].znak=='B'){
									G[GRAF[i][j].l].push_back(GRAF[i+1][j].l);
                      			  G[GRAF[i+1][j].l].push_back(GRAF[i][j].l);
								}
							} 
							
							if( j>=1 ){
								if(GRAF[i][j-1].znak=='B'){
									 G[ilosc].push_back(GRAF[i][j-1].l);
                      			  G[GRAF[i][j-1].l].push_back(ilosc);
								}	
							  }
							if((j+1)<m){
								if(GRAF[i][j+1].znak=='B'){
									G[ilosc].push_back(GRAF[i][j+1].l);
                      			  G[GRAF[i][j+1].l].push_back(ilosc);
								}	 
							}
							
							ilosc++;				
						}
					  }
              }
              //cout << "ciuchcia" << endl;

              for(int i=0;i<=ilosc;i++){
                      m1[i]=-1;
                      m2[i]=-1;
              }
//cout << "AAA" << endl;

              while(true){
              //	cout << "OBRTO DUZY" << endl;
                      for(int i=0;i<=ilosc;i++) visited[i]=0;
                      bool ok = 0;
                      for(int i=0;i<ilosc;i++){
                              if(m1[i]==(-1)){
                                      if(dfs(i)){
                                              ok = 1;
                                      }
                              }
                      }
                      if(!ok) break;
              }
             // cout << "BATERIAAA" <<endl;
              
			//cout << "ILOSC W: "<< ilosc << endl; 
              for(int i=0;i<ilosc;i++){
                      if(m1[i]==(-1) && krop[i]==0){
                      	//cout << i << " dada" << endl;
                              cout << "NIE" << endl;
                              goto poza;
                      }
              }
              cout << "TAK" << endl;
              poza:;
      }
}
