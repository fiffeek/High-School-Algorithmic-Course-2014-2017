#include <iostream>
#include <vector>

using namespace std;

vector <int> G[1000005];
int in[1000005];
int out[1000005];
bool vis[1000005];
int kol[1000005];

const int LOGARYTM = 21;

vector <int> jump[1000005];

int u,polanastartowa;
void dfs(int a, int k){
      vis[a]=1;
      in[a]=u;
      kol[a]=k;
      u++;

      int liczba=G[a].size();
      for(int j=0;j<liczba;j++){
            if(vis[G[a][j]]==0){
                dfs(G[a][j],k+1);
                jump[G[a][j]].push_back(a);
            }
      }

      out[a]=u;
      u++;
}

void laq(int n,int m){
      for(int i=1;i<=LOGARYTM;i++){
              for(int l=1;l<=n;l++){
                      if(l!=m) jump[l].push_back(jump[jump[l][i-1]][i-1]);
              }
      }
}

bool czydziala(int i, int j){
      return ((in[i]>=in[j] && out[i]<=out[j]));
}

int lca(int i, int j){
      if(czydziala(i,j)) return j;
      if(czydziala(j,i)) return i;
      int l=LOGARYTM;
      while(l>=0){
              if(czydziala(j,jump[i][l])) l--;
              else i=jump[i][l];
      }
      return jump[i][0];
}

int la(int i,int il){
     if(il==0) return i;
      if(il==1) return jump[i][0];
      int p=1,zmienna=0;
      while(p<=il){ 
	  	p=p*2;
     	zmienna++;
  	  }
  	  p=p/2;
  	  //cout << i << " " << il << " " << zmienna-1 << " " << p << endl;
      la(jump[i][zmienna-1],il-p);
}

int main(){
      int z;
      cin >> z;
      while(z--){
              u=0;
              int n ,m , k;
              cin >> n >> m >> k;
              for(int i=0;i<=n;i++){
                      vis[i]=0;
                      in[i]=0;
                      out[i]=0;
                      G[i].clear();
                      jump[i].clear();
                      kol[i]=0;
              }

              for(int i=1;i<n;i++){
                      int a,b;
                      cin >> a >> b;
                      G[a].push_back(b);
                      G[b].push_back(a);
              }
              for(int i=0;i<=LOGARYTM;i++) jump[m].push_back(m);
              dfs(m,0);
              laq(n,m);
              polanastartowa = m;
              while(k--){
                      int c,t;
                      cin >> c >> t;

                      int wierz = lca(polanastartowa,c);
                      //cout << polanastartowa << " "<< c << " " << wierz << endl;
                      //cout << kol[polanastartowa] - kol[wierz] << "ODL LCA OD WIERZ" << endl;
                      if(t==(kol[polanastartowa]-kol[wierz])){
                              polanastartowa=wierz;
                      }else if(t<(kol[polanastartowa]-kol[wierz])){
                              polanastartowa=la(polanastartowa,t);
                      }else{
                              t=t-(kol[polanastartowa]-kol[wierz]);
                              t=(kol[c]-kol[wierz])-t;
                              //cout << "odl c i wierz " << kol[c] - kol[wierz] << endl;
                              
                              if(t<=0) polanastartowa=c;
                              else{
                             //cout << "TO T  : " << t << " a to lact " << la(c,t) << endl; 	
							  polanastartowa=la(c,t);
                      		}
					  }

                      cout << polanastartowa << " ";

              }
              cout << endl;

      }
}
