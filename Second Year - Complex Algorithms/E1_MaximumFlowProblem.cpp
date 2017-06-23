#include <iostream>
#include <queue>
#include <vector>


using namespace std;

long long cap[105][105];
long long rezydualna[105][105];
long long parent[105];
long long aktualnacap[105];

vector <long long> siec[105];

void czyszczenie(long long n){
      for(long long i=0;i<=n;i++){
              siec[i].clear();
              for(long long j=0;j<=n;j++){
                      cap[i][j]=0;
                      rezydualna[i][j]=0;
              }
      }
}

long long przeplyw(long long s, long long t,long long n){
      long long odp = 0;

      while(true){
              for(long long i=0;i<=n;i++) parent[i]=(-1);
              parent[s]=(-2);

              for(long long j=0;j<=n;j++) aktualnacap[j]=0;
              aktualnacap[s]=1000000001;

              queue<long long> q;
              if(q.empty()==false) q.pop();
              q.push(s);
              while(q.empty()==false){
                      long long wierzch = q.front();
                      q.pop();

                      for(long long i=0;i<siec[wierzch].size();i++){
                              long long potomek = siec[wierzch][i];
                              if(parent[potomek]==(-1) && ((cap[wierzch][potomek]-rezydualna[wierzch][potomek])>0)){
                                      parent[potomek]=wierzch;
                                      aktualnacap[potomek] = min(aktualnacap[wierzch],cap[wierzch][potomek]-rezydualna[wierzch][potomek]);
                                      if(potomek!=t) q.push(potomek);
                                      else goto wyjsc;
                              }
                      }
              }
              wyjsc:
              long long maksymalnyprzeplyw = aktualnacap[t];
              if(maksymalnyprzeplyw==0) goto poza;

              odp+=maksymalnyprzeplyw;

              long long potomek=t;
              while(potomek!=s){
                      long long rodzic = parent[potomek];
                      rezydualna[rodzic][potomek]+=maksymalnyprzeplyw;
                      rezydualna[potomek][rodzic]-=maksymalnyprzeplyw;
                      potomek = rodzic;
              }

      }
      poza:

      return odp;
}



int main(){
      long long z;
      cin >> z;
      while(z--){
              long long n,m,s,t;
              cin >> n >> m >> s >> t;
              czyszczenie(n);
                        for(long long i=0;i<m;i++){
                      long long a,b,d;
                      cin >> a >> b >> d;
                      if(cap[a][b]==0) cap[a][b]=d;
                      else cap[a][b]+=d;
                      siec[a].push_back(b);
                      siec[b].push_back(a);
              }

              cout << przeplyw(s,t,n) << endl;
      }
}
